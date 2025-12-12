// ***************************************************************************************************** //
// my personal library, "Extended". only vector2 functionalities so far, more stuff i'll add on the way. //
// ***************************************************************************************************** //

#ifndef EXT_H
#define EXT_H

#include <cmath>

class ext {
public:
    struct FVec2 {
        float x, y;

        FVec2 operator+(const FVec2& other) const {
            return FVec2{x + other.x, y + other.y};
        }
        FVec2 operator-(const FVec2& other) const {
            return FVec2{x - other.x, y - other.y};
        }

        FVec2& operator+=(const FVec2& other) {
            x += other.x;
            y += other.y;
            return *this;
        }
        FVec2& operator-=(const FVec2& other) {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        FVec2 operator*(const float& other) const {
            return FVec2{x * other, y * other};
        }
        FVec2 operator/(const float& other) const {
            return FVec2{x / other, y / other};
        }
    };
    struct IVec2 {
        int x, y;

        IVec2 operator+(const IVec2& other) const {
            return IVec2{x + other.x, y + other.y};
        }
        IVec2 operator-(const IVec2& other) const {
            return IVec2{x - other.x, y - other.y};
        }

        IVec2& operator+=(const IVec2& other) {
            x += other.x;
            y += other.y;
            return *this;
        }
        IVec2& operator-=(const IVec2& other) {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        IVec2 operator*(int other) const {
            return IVec2{x * other, y * other};
        }
    };
    inline const static double pi = 2 * std::acos(0.0);
};

#endif