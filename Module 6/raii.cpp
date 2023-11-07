#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileHandler {
private:
    fstream file;

public:
    // Constructor - Acquire the resource
    FileHandler(const string& filename) {
        file.open(filename, ios::in | ios::out | ios::app);
        if (!file.is_open()) {
            throw runtime_error("Could not open file");
        }
        cout << "File opened successfully" << endl;
    }

    // Destructor - Release the resource
    ~FileHandler() {
        file.close();
        cout << "File closed" << endl;
    }

    // Allow reading from the file
    void read(string& outString) {
        if (!file.read(&outString[0], outString.size())) {
            // handle read error
        }
    }

    // Allow writing to the file
    void write(const string& inString) {
        if (!file.write(inString.c_str(), inString.size())) {
            // handle write error
        }
    }

    // Disabling copy constructor and assignment operator
    FileHandler(const FileHandler&) = delete;
    FileHandler& operator=(const FileHandler&) = delete;
};

int main() {
    try {
        FileHandler fh("example.txt");
        // Use fh to read from and write to the file...

        // When fh goes out of scope, its destructor is called automatically
        // which closes the file. No need for explicit cleanup code.
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        // The file is still closed properly even if an exception is thrown
    }
    return 0;
}
