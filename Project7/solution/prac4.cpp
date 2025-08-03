#include <iostream>
#include <string>

using namespace std;

void fillWithM(string &text)
{
    for (auto &character : text) {
        character = 'm';
    }
}

void fillWithM_2(string &text)
{
    for (int index{}; index < text.size(); index++) {
        text[index] = 'm';
    }
}

int main()
{
    string hello{"Hello world!"};
    cout << "Before: " << hello << endl;

    fillWithM(hello);

    cout << "After:  " << hello << endl;

    cout << "------------------------------------------------------------------"
            "----------\n\n";

    string hello2{"Hello World!"};
    cout << "Before: " << hello2 << endl;

    fillWithM_2(hello2);

    cout << "After:  " << hello2 << endl;
}
