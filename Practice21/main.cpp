#include <iostream>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main() {
    try {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help", "produce help message")
            ("file", po::value<std::string>(), "set input file");

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("help")) {
            std::cout << desc << std::endl;
            return 0;
        }

        if (vm.count("file")) {
            std::string filename = vm["file"].as<std::string>();
            std::ifstream file(filename);
            if (file) {
                std::cout << file.rdbuf();
            } 
            else {
                std::cerr << "Error opening file: " << filename << std::endl;
            }
        }
    } 
    catch (std::exception e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}