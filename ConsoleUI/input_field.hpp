#pragma once

#include <iostream>
#include <string>
#include <sys/ioctl.h>

#include "utils.hpp"
#include "element.hpp"
#include "window_settings.hpp"
#include "format_string.hpp"


using namespace std;


class InputField : public Element {
    private:
        string label;
        int input_offset = 20;
        int input_width;

    public:
        InputField() : Element(2, NULL) {
            label = "";
        }
        InputField(string _label, Result* res = NULL) : Element(2, res) {
            label = _label;
        }
        InputField(string _label, int _input_width, Result* res = NULL) : Element(2, res) {
            label = _label;
            input_width = _input_width;
            // input_offset = (cols - _input_width) / 2;
        }

        void show(WindowSettings root) {

            input_offset = (root.cols - input_width) / 2;
            // clear_screen();
            // cout << get_cursor_down_string(root.rows / 2 - 2);

            // cout << rows << " " << cols << endl;
            int label_offset = (root.cols - label.length()) / 2;
            int current_input_offset = (input_offset == -1 ? label_offset : input_offset);
            cout
                << get_color_string(mult_str(" ", label_offset), White, Black)
                << get_color_string(label, White, Black)
                << get_color_string(mult_str(" ", label_offset), White, Black)
                << endl;
            cout
               << get_color_string(mult_str(" ", current_input_offset), White, Black, false)
               << get_color_string(mult_str(" ", root.cols - current_input_offset * 2), White, Blue, false)
               << get_color_string(mult_str(" ", current_input_offset), White, Black, false)
               << get_color_string(mult_str(" ", 0), Black, Blue, Bold, false)
               << get_cursor_left_string(root.cols - current_input_offset - 1);

            //    << get_color_string(mult_str(" ", input_offset == -1 ? label_offset : input_offset), White, Black, false);

            string inp;
            getline(cin, inp);
            cout << get_reset_string();
            if (result != NULL)
                result->result_string = inp;
        }

};

