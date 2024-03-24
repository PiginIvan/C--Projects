#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::fstream fstr;
    std::stringstream ss;
    std::string input;
    getline(std::cin, input);
    ss.str(input);
    std::string cat, filename;
    ss >> cat >> filename;
    fstr.open(filename, std::ios::in);
    std::string buf;
    while (getline(fstr, buf)) {
        std::cout << buf << std::endl;
    }
    fstr.close();
    return 0;
}