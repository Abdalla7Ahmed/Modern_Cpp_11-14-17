// this library introduction in c++17

/* #include<iostream>
#include <experimental/filesystem>

    int main(int argc, char const *argv[])
{
    std::experimental::filesystem::path p{"/home/abdallah/Documents/c++new/File_IO"};
    if (p.has_filename())
    {
        std::cout << p.filename() << std::endl;
    }
    return 0;
}

// g++ Filesystem.cpp -std=c++17 -lstdc++fs

*/

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main()
{
    // Create a path object pointing to a file.
    fs::path p("/home/abdallah/Documents/c++new/File_IO/example.txt");
    std::cout << "Original path: " << p << "\n\n";

    // filename(): Returns the filename (last component) of the path.
    // For our example, this returns "example.txt".
    std::cout << "Filename: " << p.filename() << "\n";

    // extension(): Returns the file extension.
    // For our example, this returns ".txt".
    std::cout << "Extension: " << p.extension() << "\n";

    // stem(): Returns the filename without the extension.
    // For our example, this returns "example".
    std::cout << "filename without the extension Stem: " << p.stem() << "\n";

    // parent_path(): Returns the path of the parent directory.
    // This strips off the filename and returns the directory path.
    std::cout << "Parent path: " << p.parent_path() << "\n";

    // has_filename(): Checks if the path contains a filename.
    // Returns true if there is a filename component.
    std::cout << "Has filename? " << (p.has_filename() ? "true" : "false") << "\n";

    // has_extension(): Checks if the path has an extension.
    // Returns true if the filename includes an extension.
    std::cout << "Has extension? " << (p.has_extension() ? "true" : "false") << "\n";

    // replace_extension(): Replaces the current extension with a new one.
    // Here, we change ".txt" to ".md".
    fs::path modifiedPath = p;
    modifiedPath.replace_extension(".md");
    std::cout << "Modified path (new extension): " << modifiedPath << "\n";

    // Demonstrating path concatenation using operator/
    // This appends additional directory components to a path.
    fs::path appendedPath = p.parent_path() / "new_directory" / p.filename();
    std::cout << "Appended path: " << appendedPath << "\n";

    // Define the directory you want to iterate over.
    // Change the path below to one that exists on your system.
    fs::path dir_path("/home/abdallah/Documents/c++new/File_IO");

    try
    {
        // Check if the given path exists and is a directory.
        if (fs::exists(dir_path) && fs::is_directory(dir_path))
        {
            // Create a directory iterator that goes through each entry in the directory.
            for (const auto &entry : fs::directory_iterator(dir_path))
            {
                // 'entry' is of type fs::directory_entry, which represents a file or subdirectory.
                std::cout << "Entry path: " << entry.path() << "\n";

                // Check if the entry is a regular file.
                if (fs::is_regular_file(entry.status()))
                    std::cout << "  -> This is a regular file named: "
                              << entry.path().filename() << "\n";
                // Check if the entry is a directory.
                else if (fs::is_directory(entry.status()))
                    std::cout << "  -> This is a directory named: "
                              << entry.path().filename() << "\n";
                // You can add more checks (e.g., symlink, etc.) as needed.
            }
        }
        else
        {
            std::cerr << "Error: The path does not exist or is not a directory.\n";
        }
    }
    catch (const std::exception &ex)
    {
        // Catch and display any exceptions that occur during directory iteration.
        std::cerr << "Exception: " << ex.what() << "\n";
    }

    return 0;
}
