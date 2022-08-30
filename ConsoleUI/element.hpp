#pragma once

#include <iostream>
#include <sys/ioctl.h>

#include "format_string.hpp"
#include "result.hpp"
#include "window_settings.hpp"

using namespace std;

class Element {
    protected:
        Result* result;
        
    public:
        // int top_offset;
        // int left_offset;
        int height;


        Element(int _height) {
            height = _height;
        }
        Element(int _height, Result* _result) {
            height = _height;
            result = _result;
        }

        // Element(int _left_offset = 0, int _top_offset = 0) {
        //     left_offset = _left_offset;
        //     top_offset = _top_offset;
        // }

        virtual void show(WindowSettings root) {

        }

};
