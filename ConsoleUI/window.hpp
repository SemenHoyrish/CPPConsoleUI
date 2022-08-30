#pragma once

#include <iostream>
#include <vector>
#include <sys/ioctl.h>

#include "element.hpp"
#include "input_field.hpp"
#include "format_string.hpp"

using namespace std;


class Window {
    protected:
        vector<Element*> elements;

        void clear_screen(COLOR color = Black) {
            for(int i = 0; i < rows; i++)
                cout << get_color_string(mult_str(" ", cols), White, color) << endl;

            cout << get_cursor_up_string(rows);
        }

    public:
        int rows = 0;
        int cols = 0;

        Window() {
            winsize w;
            ioctl(0, TIOCGWINSZ, &w);

            rows = w.ws_row;
            cols = w.ws_col;

            // cout << rows << " " << cols << endl;
        }

        void add_element(Element* e) {
            elements.push_back(e);
        }

        void show() {
            clear_screen();
            int parts = elements.size() + 1;
            int offset = rows / parts;
            for (Element* e : elements) {
                for (int i = 0; i < offset - e->height / 2; ++i)
                    cout << get_color_string(mult_str(" ", cols), White, Black, false) << endl;
                e->show(WindowSettings(rows, cols, "Untitled"));
            }
        }

};
