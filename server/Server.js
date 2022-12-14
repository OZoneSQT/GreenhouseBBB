/*
 * Authors:
 * Bastian Durand 329735
 * Michel Sommer 273966
 * Date: 2022-11-15
 *
 * Requirements: 
 *              See temp
 *              See humidity
 *              See ligh intensity
 *              See window open or closed
 *              See heater status
 *              Set light intensity level
 *              Set window open or closed
 *              Set heater status
 */
 
//Loading modules
var http = require('http');
var fs = require('fs');
var path = require('path');

const execute = require('child_process').execSync;  
const executeFile = require('child_process').execFile; // Execute file


//Set light to default 0
executeFile('./greenhouse', ['setLedLight', '0'], (error, stdout, stderr) => { if(error) { throw error;} });

//Set window to default closed
executeFile('./greenhouse', ['setWindowStatus', 'close'], (error, stdout, stderr) => { if(error) { throw error;} });

//Set window to default closed
executeFile('./greenhouse', ['setHeaterStatus', 'off'], (error, stdout, stderr) => { if(error) { throw error;} });


// Initialize the server on port 26001
var server = http.createServer(function (request, result) {
    var file = '.'+((request.url=='/')?'/index.html':request.url);
    var fileExtension = path.extname(file);
    var contentType = 'text/html';

    fs.exists(file, function(exists){
        if(exists){
            fs.readFile(file, function(error, content){
                if(!error){
                    result.writeHead(200,{'content-type':contentType});
                    result.end(content);
                }
            });
        }
        else{
            result.writeHead(404);
            result.end('Page not found');
        }
    });
}).listen(26001);


// Loading socket io module
var io = require('socket.io')(server);


// When communication is established
// Recieve client requests
io.on('connection', function (socket) {
    // Pass the socket and the data that was sent to the function.
    socket.on('refreshData', (data) => handleRefreshData(socket, data));
    socket.on('changeLightState', (data) => handleChangeLightState(socket, data));
    socket.on('changeWindowState', (data) => handleChangeWindowState(socket, data));
    socket.on('changeHeaterState', (data) => handleChangeHeaterState(socket, data));
});


// Read all current values form the peripherals and return it to the client that is connected to socket
async function handleRefreshData(socket, data) {
    var temperature = "Na"
    var humidity = "Na"
    var light = "Na"
    var window = "Na"
    var heater = "Na"
    var ledLight = "Na"


    // Read humidity/temperature
    var result = execute('./greenhouse readTempAndHumidity');
    strings = result.toString("utf8").split('\n');
    temperature = strings[0].substring(13, 17);
    humidity = strings[1].substring(13, 17);

    // Perform synchronus calls to the peripheral, get result then parse it

    //Read light
    var result = execute('./greenhouse readLightLevel');
    light = result.toString("utf8").substring(13, 18);

    //Read window
    var result = execute('./greenhouse readWindow');
    window = result.toString("utf8").substring(13, 19);

    //Read heater
    var result = execute('./greenhouse readHeater');
    heater = result.toString("utf8").substring(13, 16);

    //Read led light
    var result = execute('./greenhouse readLedLight');
    ledLight = result.toString("utf8").substring(13, 19);
  
    // Compile every result into specific json dictionary and send it to user
    socket.emit("responseRefresh", 
        {
            temperature: temperature,
            humidity: humidity,
            light: light,
            window: window,
            heater: heater,
            ledLight: ledLight
        }
    );
}


// Handle user changing led light state
async function handleChangeLightState(socket, data) {
    // Parse the json data into a dictionary
    var newData = JSON.parse(data);

    // Asynchronously change the state of the led light by passing what functionality to perform
    // and parameter to set
    executeFile('./greenhouse', ['setLedLight', newData.state], (error, stdout, stderr) => {
        if(error) { 
            throw error;
        }
        
        // After each modify peripheral call make call to read the current state and return that to the client.

        // Read led light
        var result = execute('./greenhouse readLedLight');
        var ledLight = result.toString("utf8").substring(13, 19);
        
        socket.emit("responseSetLight", 
            {
                ledLight: ledLight
            }
        );
    });
}


// Handle user changing led Window state
async function handleChangeWindowState(socket, data) {
    var newData = JSON.parse(data);
    var command;
    
    if(newData.state == 1){
        command = "open"
    } else if(newData.state == 2){
        command = "half"
    } else {
        command = "close"
    }
    
    executeFile('./greenhouse', ['setWindowStatus', command], (error, stdout, stderr) => {
        if(error) { 
            throw error;
        }

        // After each modify peripheral call make call to read the current state and return that to the client.
        
        //Read window
        var result = execute('./greenhouse readWindow');
        var window = result.toString("utf8").substring(13, 19);

        socket.emit("responseSetWindow", 
            {
                window: window
            }
        );
    });
}


// Handle user changing led Heater state
async function handleChangeHeaterState(socket, data) {
    var newData = JSON.parse(data);
    
    if(newData.state == 1){
        command = "on"
    } else {
        command = "off"
    }
    
    executeFile('./greenhouse', ['setHeaterStatus', command], (error, stdout, stderr) => {
        if(error) { 
            throw error;
        }

        // After each modify peripheral call make call to read the current state and return that to the client.
        
        //Read heater
        var result = execute('./greenhouse readHeater');
        var heater = result.toString("utf8").substring(13, 16);
        
        socket.emit("responseSetHeater", 
            {
                heater: heater
            }
        );
    });
}


// Displaying a console message for user feedback
console.log("Server Running ...");