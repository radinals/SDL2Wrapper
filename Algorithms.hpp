#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <list>
#include "Point.hpp"
#include "Rect.hpp"

namespace Algorithms {
    // check for the biggest number before subtracting a with b
    inline constexpr int maxSubtract(int a,int b) {
        return (a > b) ? (a-b) : (b-a);
    }

    inline constexpr int getHalf(int n) { return  n / 2.0F;}

    // allign a with b, return a centered a copy
    Rect_t alignCenter(const Rect_t& a, const Rect_t& b);
};

#endif // !ALGORITHMS_HPP
