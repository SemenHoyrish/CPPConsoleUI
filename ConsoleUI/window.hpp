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
            for(int i = 0; i < rows; i++) {
                if (i + 1 < rows)
                    cout << get_color_string(mult_str(" ", cols), White, color) << endl;
                else
                    cout << get_color_string(mult_str(" ", cols), White, color);
            }

            cout << get_cursor_up_string(rows);
            cout << get_cursor_left_string(cols);
        }

        int get_elements_total_height() {
            int res = 0;
            for (Element* e : elements)
                res += e->height;
            return res;
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


        // 31 - 2 - 2 = 27 / 3 = 9
        // 10 8 8

        void show() {
            clear_screen();
            int parts = elements.size() + 1;
            // int offset = rows / parts;
            int offset = (rows - get_elements_total_height()) / parts;
            for (Element* e : elements) {
                // for (int i = 0; i < offset - e->height / 2; ++i)
                for (int i = 0; i < offset; ++i)
                    cout << get_color_string(mult_str(" ", cols), White, Black, false) << endl;
                e->show(WindowSettings(rows, cols, "Untitled"));
            }
        }

};
