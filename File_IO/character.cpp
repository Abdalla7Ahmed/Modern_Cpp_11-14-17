#include <iostream>
#include <fstream>
#include <string>
void write(void)
{
    std::ofstream out{"test.txt"};
    std::string message{"C++ : File Input/Output"};
    for (const auto &ch : message)
    {
        // write single character
        // return the position of the put function
        std::cout << "The current position of the put pointer is: " << out.tellp() << std::endl;
        out.put(ch);
    }
    out.seekp(10);
    out.put('$');
    out.close();
}

void read(void)
{
    std::ifstream input("test.txt");
    // return the position of the get function
    std::cout << "The current position of the get pointer is: " << input.tellg() << std::endl;

    input.seekg(5);                // make the get pointer point to the fivth position
    input.seekg(5, std::ios::beg); // 5 from the begining
    input.seekg(5, std::ios::cur); // 5 from the current
    input.seekg(5, std::ios::end); // 5 from the end

    char ch;
    // read single character
    while (input.get(ch))
    {
        std::cout << ch;
    }
    std::cout << std::endl;
    input.close();
}
void fstream(void)
{
    std::fstream stream{"stream.txt"}; // by default std::ios::out | std::ios::in
    if (!stream.is_open())
    {
        // if the file doesn't exist , the fstream class will not create it
        std::cout << "File does not exist" << std::endl;
        std::ofstream file{"stream.txt"};
        file.close();
        stream.open("stream.txt");
    }
    stream << "Stream class Test" << std::endl;
    // poth the get pointer and put pointer at the end character position
    std::cout << "The current position of the get pointer is: " << stream.tellg() << std::endl;
    std::cout << "The current position of the put pointer is: " << stream.tellp() << std::endl;
    stream.seekg(0);
    std::string line;
    std::getline(stream, line);
    std::cout << line << std::endl;
}
int main(int argc, char const *argv[])
{
    // write();
    // read();
    fstream();
    return 0;
}
