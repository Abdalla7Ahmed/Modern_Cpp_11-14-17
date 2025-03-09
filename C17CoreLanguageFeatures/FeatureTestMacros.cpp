#include <iostream>
#ifdef __has_include
#if __has_include(<filesystem>)
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif
#endif

int main(int argc, char const *argv[])
{
    auto f = fs::path{"/home/abdallah/C17CoreLanguageFeatures"};
    std::cout << f.filename() << "\n";
    std::cout << __cpp_inline_variables << std::endl;
    std::cout << __cpp_capture_star_this << std::endl;

    return 0;
}

/*
__has_include is useful for conditional compilation based on available headers.
*/