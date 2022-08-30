#pragma once

#include <iostream>

using namespace std;

string mult_str(string s, int n) {
    string r = "";
    for (int i = 0; i < n; i++)
        r += s;
    return r;
}
