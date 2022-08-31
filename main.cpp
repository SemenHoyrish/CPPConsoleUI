#include <iostream>

#include "ConsoleUI/window.hpp"
#include "ConsoleUI/input_field.hpp"
#include "ConsoleUI/element.hpp"
#include "ConsoleUI/format_string.hpp"

using namespace std;



int main() {
    // cout << "HELLO!" << endl;

    // Element* el = new Element();


    // InputField* name_field = new InputField("Your name", 16);
    // string name = name_field->show();

    // cout << name << endl;
    // for(auto c : name) {
    //     cout << c << endl;
    // }


    Result* r = new Result();

    Window* window = new Window();
    InputField* name_field = new InputField("Your name", 16, r);
    window->add_element(name_field);
    InputField* name_field2 = new InputField("Your surname", 16);
    window->add_element(name_field2);
    window->show();

    // cout << "rows " << window->rows << endl;
    // cout << "cols " << window->cols << endl;
    // cout << r->result_string << endl;

}
