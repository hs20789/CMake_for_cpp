#include <memory>
#include <print>

import SpreadsheetCell;

int main()
{
    // 1. 스택에 객체 생성
    SpreadsheetCell myCell1, anotherCell1;
    myCell1.setValue(6);
    anotherCell1.setString("3.2");
    std::print("cell1: {}\n", myCell1.getValue());
    std::print("cell2: {}\n", anotherCell1.getValue());
    std::print("cell2: {}\n", anotherCell1.getString());

    // 2. 프리스토어에 객체 생성
    SpreadsheetCell *myCellp1{new SpreadsheetCell{}};
    myCellp1->setValue(3.7);
    std::print("cell1: {} | {}\n", myCellp1->getValue(), myCellp1->getString());

    (*myCellp1).setValue(10.4);
    std::print("cell1: {} | {}\n", (*myCellp1).getValue(),
               (*myCellp1).getString());
    delete myCellp1;
    myCellp1 = nullptr;

    // 3. 스마트포인터 사용
    std::unique_ptr<SpreadsheetCell> smartPtr1{new SpreadsheetCell{}};
    smartPtr1->setValue(3.14);
    std::print("smartPtr1: {} | {}\n", smartPtr1->getValue(),
               smartPtr1->getString());
    auto smartPtr2 = std::unique_ptr<SpreadsheetCell>{new SpreadsheetCell{}};
    smartPtr2->setValue(100.34);
    std::print("smartPtr2: {} | {}\n", smartPtr2->getValue(),
               smartPtr2->getString());
    auto smartPtr3 = std::make_unique<SpreadsheetCell>();
    smartPtr3->setString("hihi");
    std::print("smartPtr3: {} | {}\n", smartPtr3->getValue(),
               smartPtr3->getString());

    std::print("==============================================================="
               "=======================================\n");
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    SpreadsheetCell myCell2(5), anotherCell2(4);
    std::print("cell1: {}\ncell2: {}\n", myCell2.getValue(),
               anotherCell2.getValue());
    SpreadsheetCell myCell3{10}, anotherCell3{8};
    std::print("cell1: {}\ncell2: {}\n", myCell3.getValue(),
               anotherCell3.getValue());

    auto smartPtr4{std::make_unique<SpreadsheetCell>(32091)};
    std::print("smartPtr4: {} | {}\n", smartPtr4->getValue(),
               smartPtr4->getString());

    auto smartPtr5{std::unique_ptr<SpreadsheetCell>{new SpreadsheetCell{490}}};
    std::print("smartPtr5: {} | {}\n", smartPtr5->getValue(),
               smartPtr5->getString());

    SpreadsheetCell myCell4{"test"}, anotherCell4{4.4};
    auto smartPtr6{std::make_unique<SpreadsheetCell>("5.5")};
    std::print(
        "myCell4{{\"test\"}}: {}\nanotherCell4{{4.4}}: {}\nsmartPtr6: {}\n",
        myCell4.getValue(), anotherCell4.getValue(), smartPtr6->getValue());
}