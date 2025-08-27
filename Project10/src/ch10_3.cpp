#include <format>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

import StringSpreadsheetCell_ch10;
import DoubleSpreadsheetCell_ch10;

int main()
{
    std::vector<std::unique_ptr<SpreadsheetCell>> cellArray;

    cellArray.push_back(std::make_unique<StringSpreadsheetCell>());
    cellArray.push_back(std::make_unique<StringSpreadsheetCell>());
    cellArray.push_back(std::make_unique<DoubleSpreadsheetCell>());

    cellArray[0]->set("hello");
    cellArray[1]->set("10");
    cellArray[2]->set("18");

    std::cout << std::format("Vector: [{} {} {}]", cellArray[0]->getString(),
                             cellArray[1]->getString(),
                             cellArray[2]->getString())
              << std::endl;

    std::unique_ptr<SpreadsheetCell> ptr1{
        std::make_unique<StringSpreadsheetCell>()};
    ptr1->set("33");
    std::unique_ptr<SpreadsheetCell> ptr2{
        std::make_unique<DoubleSpreadsheetCell>()};
    ptr2->set("44");
    DoubleSpreadsheetCell convert{};
    convert.set("55");
    std::unique_ptr<SpreadsheetCell> ptr3{
        std::make_unique<StringSpreadsheetCell>(convert)};
    ptr3->set("55");
    std::cout << std::format("ptr1, ptr2, ptr3: [{} {} {}]\n",
                             ptr1->getString(), ptr2->getString(),
                             ptr3->getString());

    DoubleSpreadsheetCell op1;
    StringSpreadsheetCell op2;
    op1.set(8.4);
    op2.set("8.2");
    StringSpreadsheetCell result{op1 + op2};
    std::cout << "result: " << result.getString() << std::endl;


}