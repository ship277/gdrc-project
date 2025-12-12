#ifndef RAY_H
#define RAY_H

#include "Ext.h"

class Ray {
public:
    Ray();
    void castRay();
    void drawRay();

private:
    ext::FVec2 targetPx;
    ext::IVec2 nTileIndex;
};

#endif