/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 19-11-2022
 */

#ifndef GREENHOUSEBBB_SERVOADAPTER_H
#define GREENHOUSEBBB_SERVOADAPTER_H

namespace greenhouse {
    class servoAdapter {

    private:
        void controlServo(std::string i);

    public:
        openWindow();
        halfOpenWindow();
        closeWindow();
        readWindowPos();

    };
}

#endif //GREENHOUSEBBB_SERVOADAPTER_H