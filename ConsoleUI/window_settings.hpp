#pragma once

#include <iostream>
#include <sys/ioctl.h>

#include "format_string.hpp"

using namespace std;

struct WindowSettings {
    int rows;
    int cols;
    string name;

    WindowSettings(int _rows, int _cols, string _name) {
        rows = _rows;
        cols = _cols;
        name = _name;
    }
};
