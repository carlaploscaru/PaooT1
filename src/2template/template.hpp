#pragma once//contents of header included only once
#include "../1booking/class.hpp" 
#include <iostream>



template <typename T>
class Template {
private:
    T value;

public:
    Template() : value(T()) {}
    Template(T val) : value(val) {}

    T getValue() const {
        return value;
    }

    void setValue(T val) {
        value = val;
    }
};

