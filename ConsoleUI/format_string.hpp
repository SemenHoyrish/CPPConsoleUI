#pragma once

#include <iostream>
#include <map>

#include "utils.hpp"


using namespace std;


enum COLOR {
    Black,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White
};

enum STYLE {
    Default,
    Underline,
    Bold
};

map<COLOR, int> ForegroundColors = {
    { Black, 30 },
    { Red, 31 },
    { Green, 32 },
    { Yellow, 33 },
    { Blue, 34 },
    { Magenta, 35 },
    { Cyan, 36 },
    { White, 37 }
};

map<COLOR, int> BackroundColors = {
    { Black, 40 },
    { Red, 41 },
    { Green, 42 },
    { Yellow, 43 },
    { Blue, 44 },
    { Magenta, 45 },
    { Cyan, 46 },
    { White, 47 }
};

map<STYLE, int> Styles = {
    { Default, 0 },
    { Underline, 4 },
    { Bold, 1 }
};

string get_color_string(string text, COLOR fg, COLOR bg, STYLE style, bool reset=true) {
    return "\x1b[" + to_string(Styles[style]) + ";" + to_string(ForegroundColors[fg]) + ";" + to_string(BackroundColors[bg]) + "m" + text + (reset ? "\x1b[0m" : "");
}
string get_color_string(string text, COLOR fg, bool reset=true) {
    return get_color_string(text, fg, COLOR::Black, STYLE::Default, reset);
}
string get_color_string(string text, COLOR fg, COLOR bg, bool reset=true) {
    return get_color_string(text, fg, bg, STYLE::Default, reset);
}
string get_color_string(string text, COLOR fg, STYLE style, bool reset=true) {
    return get_color_string(text, fg, COLOR::Black, style, reset);
}
string get_reset_string() {
    return "\x1b[0m";
}

string get_cursor_left_string(int n) {
    return "\x1b[" + to_string(n) + "D";
}
string get_cursor_right_string(int n) {
    return "\x1b[" + to_string(n) + "C";
}
string get_cursor_up_string(int n) {
    return "\x1b[" + to_string(n) + "A";
}
string get_cursor_down_string(int n) {
    return "\x1b[" + to_string(n) + "B";
}
