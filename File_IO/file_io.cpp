#include <iostream>
#include <fstream>
#include <string>
void write(void)
{
    std::ofstream out{"test.txt"};
    // or we can use the open method instead of constructor
    // out.open("test.txt");
    out << "Hello world" << std::endl;
    out << 10 << std::endl;
    out.close();
}

void read(void)
{
    std::ifstream input{"test.txt"};
    std::string message;

    if (!input.is_open())
    {
        std::cout << "Couldn't open the file" << std::endl;
        return;
    }
    std::getline(input, message);
    int value{};
    input >> value;
    std::cout << message << " : " << value << std::endl;
    // Check the state of the stream after successful reads.

    // eof(): Returns true if the end-of-file has been reached.
    // input >> value; // if we try to read and there is no more data , eof flag will set to be true

    if (input.eof())
        std::cout << "Reached end of file (eof flag is set)." << std::endl;
    else
        std::cout << "Not at the end of file yet (eof flag is not set)." << std::endl;
    // good(): Returns true if none of the error state flags (eof, fail, bad) are set.
    if (input.good())
        std::cout << "Stream is in good state (no errors)." << std::endl;
    else
        std::cout << "Stream is not in good state." << std::endl;
    if (input.fail())
        std::cout << "Attempting to read extra data caused failbit to be set." << std::endl;

    // bad(): Returns true if a fatal error has occurred (e.g., loss of integrity of the stream).
    if (input.bad())
        std::cout << "Stream encountered a fatal error (badbit set)." << std::endl;
    else
        std::cout << "No fatal error (badbit not set)." << std::endl;

    // clear(): Resets the stream's error state flags (e.g., eofbit, failbit, badbit).
    input.clear();
    std::cout << "After calling clear(), stream good state: " << std::boolalpha << input.good() << std::endl;

    // setstate(): Manually sets one or more error state flags.
    // Here, we artificially set the failbit.
    input.setstate(std::ios::failbit);
    // failbit,goodbit,eofbit,badbit

    input.close();
}
int main(int argc, char const *argv[])
{
    write();
    read();
    return 0;
}
