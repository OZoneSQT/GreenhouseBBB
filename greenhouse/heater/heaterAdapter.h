/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 19-11-2022
 */

#ifndef GREENHOUSEBBB_HEATERADAPTER_H
#define GREENHOUSEBBB_HEATERADAPTER_H

namespace greenhouse {

    class heaterAdapter {

    private:

    public:
        heaterAdapter();
        void on();
        void off();
        void isRunning();

    };

}

#endif