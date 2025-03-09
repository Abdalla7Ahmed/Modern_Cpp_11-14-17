#include <iostream>
#include <fstream>
#include <string>

/*
Text mode (using operator<< without std::ios::binary):
    The integer is written out as ASCII characters (e.g., "12345678").
    Each digit becomes a character in the file, so an 8-digit number uses at least 8 bytes (often more with spaces/newlines).

Binary mode (using std::ios::binary and write/read):
    The integer is stored as its raw bytes in memory (for a 32-bit int, that’s typically 4 bytes).
    No conversion to text happens, so it usually takes less space on disk compared to the text representation.
*/

struct Record
{
    int id;
    std::string name;
};

void WriteRecord(Record R)
{
    std::ofstream binarystream("Records", std::ios::binary | std::ios::out);
    binarystream.write((const char *)&R, sizeof(Record));
    binarystream.close();
}
Record ReadRecord(void)
{
    std::ifstream binarystream("Records", std::ios::binary | std::ios::in);
    Record R;
    binarystream.read((char *)&R, sizeof(Record));
    binarystream.close();
    return R;
}

int main(int argc, char const *argv[])
{
    std::ofstream data("data");
    data << 123456789;
    std::ofstream binary("binary", std::ios::binary | std::ios::out);
    int num = 123456789;
    binary.write((const char *)&num, sizeof(int));
    binary.close();
    std::ifstream input("binary", std::ios::binary | std::ios::in);
    num = 0;
    input.read((char *)&num, sizeof(int));
    std::cout << "The value is : " << num << std::endl;

    Record R;
    R.id = 0;
    R.name = "Abdallah";
    WriteRecord(R);

    Record R2;
    R2 = ReadRecord();

    std::cout << "Id is :" << R.id << std::endl;
    std::cout << "Name is :" << R.name << std::endl;

    return 0;
}
