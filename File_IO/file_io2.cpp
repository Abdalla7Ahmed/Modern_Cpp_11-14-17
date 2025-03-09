#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
namespace fs = std::filesystem;

int main(int argc, char const *argv[])
{

    fs::path source(std::filesystem::current_path());
    source /= "source.txt";
    fs::path destination(std::filesystem::current_path());
    destination /= "destination.txt";

    std::cout << source << std::endl;
    std::cout << destination << std::endl;

    std::ofstream out{destination};
    std::ifstream input{source};

    if (!input.is_open())
    {
        std::cout << "falied to open files" << std::endl;
        return -1;
    }
    std::string line;
    while (!std::getline(input, line).eof())
    {
        out << line << std::endl;
    }

    return 0;
}
