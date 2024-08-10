#ifndef SIZE_HPP
#define SIZE_HPP

class Size_t {
public:
    Size_t() { }
    Size_t(int, int);
    Size_t(const Size_t &);

    int w = 0, h = 0;

    bool operator==(const Size_t& other) const {
        return other.w == w && other.h == h;
    }
};

#endif    // !SIZE_HPP
