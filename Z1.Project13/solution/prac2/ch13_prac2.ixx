module;

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
export module ch13_m2;
export import ch13_m1;

export class Database
{
  public:
    // Adds the given person to the database.
    void add(Person person);

    // Removes all persons from the database.
    void clear();

    // Saves all persons in the database to the given file.
    void save(std::string_view filename) const;

    // Loads all persons from the given file and stores them in the database.
    void load(std::string_view filename);

    // Outputs all persons to the given stream.
    void outputAll(std::ostream &output) const;

  private:
    std::vector<Person> m_persons;
};

using namespace std;

void Database::add(Person person) { m_persons.push_back(move(person)); }

void Database::clear() { m_persons.clear(); }

void Database::save(string_view filename) const
{
    using std::literals::operator ""s;
    std::string file =
        "C:/Users/HeonSu/source/repos/CMake_for_cpp/Project13/solution/prac2/"s +
        filename.data();
    ofstream outFile{file, ios_base::trunc};
    if (!outFile) {
        cerr << "Cannot open file: " << filename << endl;
        return;
    }

    for (const auto &person : m_persons) {
        // We need to support spaces in names.
        // So, to be able to read back names later in load(),
        // we simply quote all parts of the name.
        outFile << quoted(person.getFirstName()) << quoted(person.getLastName())
                << quoted(person.getInitials()) << endl;
    }
}

void Database::load(string_view filename)
{
    ifstream inFile{filename.data()};
    if (!inFile) {
        cerr << "Cannot open file: " << filename << endl;
        return;
    }

    while (inFile) {
        // Read line by line, so we can skip empty lines.
        // The last line in the file is empty, for example.
        string line;
        getline(inFile, line);
        if (line.empty()) { // Skip empty lines
            continue;
        }

        // Make a string stream and parse it.
        istringstream inLine{line};
        string firstName, lastName, initials;
        inLine >> quoted(firstName) >> quoted(lastName) >> quoted(initials);
        if (inLine.bad()) {
            cerr << "Error reading person. Ignoring." << endl;
            continue;
        }

        // Create a person and add it to the database.
        m_persons.push_back(
            Person{move(firstName), move(lastName), move(initials)});
    }
}

void Database::outputAll(ostream &output) const
{
    for (const auto &person : m_persons) {
        person.output(output);
    }
}
