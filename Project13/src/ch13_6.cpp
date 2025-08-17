#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::ofstream outFile{"/home/heonsu/CMake_for_cpp/Project13/docs/test.txt",
                          std::ios_base::app};
    if (!outFile.good()) {
        std::cerr << "Error while opening output file!" << std::endl;
        return -1;
    }
    outFile << "There were " << argc << " arguments to this program."
            << std::endl;
    outFile << "They are: " << std::endl;
    for (int i{}; i < argc; i++) {
        outFile << argv[i] << std::endl;
    }
}
