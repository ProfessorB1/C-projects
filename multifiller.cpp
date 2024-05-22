#include <iostream>
#include <fstream>
//Austin Farias
using namespace std;


class FileFilter {
public:
    virtual char transform(char ch) = 0;
    void doFilter(ifstream& in, ofstream& out) {
        char ch;
        while (in.get(ch)) {
            ch = transform(ch); 
            out.put(ch); 
        }
    }
};

class EncryptionFilter : public FileFilter {
private:
    int encryptionKey;
public:
    EncryptionFilter(int key) : encryptionKey(key) {}
    char transform(char ch) {
        return ch ^ encryptionKey; 
    }
};

class UppercaseFilter : public FileFilter {
public:
    char transform(char ch) {
        return toupper(ch); 
    }
};

class CopyFilter : public FileFilter {
public:
    char transform(char ch) {
        return ch;
    }
};

int main() {

    ofstream inputFile("paper.txt");
    inputFile << "This is the input file content." << endl;
    inputFile.close();

    ifstream inputFileRead("paper.txt");
    ofstream outputFile("paper.txt");

    EncryptionFilter encryptionFilter(5);
    encryptionFilter.doFilter(inputFileRead, outputFile);

    inputFileRead.close();
    outputFile.close();

    return 0;
}
