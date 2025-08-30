#include <iostream>
#include <memory>
#include <vector>
#include <initializer_list>

import SpreadsheetCell;

int main()
{
    using std::literals::string_view_literals::operator ""sv;

    SpreadsheetCell myCell1{4};
    myCell1 = 5;
    //myCell1 = "6"sv;
    SpreadsheetCell myCell2{"6"sv};

}