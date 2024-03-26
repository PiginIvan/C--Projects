#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

class WrongFilePath : public std::exception {};
class UnableOpenFile : public std::exception {};

void write_to_file(std::string filename, std::string new_string) {
    std::fstream file_exists(filename);
    if(!file_exists) {
        throw WrongFilePath();
    }
    else {
        file_exists.close();
        std::fstream file(filename, std::ios::out | std::ios::app);
        if (file.is_open()) {
            file << new_string << std::endl; 
            file.close(); 
        }
        else {
            throw UnableOpenFile();
        }
    }   
}

int main() {
    std::string filename, new_string;
    std::cout << "Please input filename" << std::endl;
    std::cin >> filename;
    std::cout << "Please input new string" << std::endl;
    std::cin >> new_string;
    try {
        write_to_file(filename, new_string);
        std::cout << "New string was added to file" << std::endl;
    }
    catch(WrongFilePath error) {
        std::cerr << "Wrong file path" << std::endl;
    }
    catch(UnableOpenFile error) {
        std::cerr << "Unable to open the file for writing." << std::endl; // Выводим сообщение об ошибке
    }
    return 0;
}