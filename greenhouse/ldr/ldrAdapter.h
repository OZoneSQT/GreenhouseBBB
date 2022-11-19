/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 19-11-2022
 */

#ifndef GREENHOUSEBBB_LDRADAPTER_H
#define GREENHOUSEBBB_LDRADAPTER_H

#define LDR_PIN 2

namespace greenhouse {

    class ldrAdapter {

    private:

    public:
        init();
        printLightLevel();
    };

}

#endif