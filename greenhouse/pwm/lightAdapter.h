/**
 * @author Bastien Durand (329735@via.dk)
 * @author Michel Sommer (273966@via.dk)
 * @date 19-11-2022
 */

#ifndef GREENHOUSEBBB_LIGHTADAPTER_H
#define GREENHOUSEBBB_LIGHTADAPTER_H

namespace greenhouse {
    class lightAdapter {

    private:

    public:
        lightAdapter() {}
        void controlLightIntensity(int i);
        void readLightIntensity();

    };
}

#endif
