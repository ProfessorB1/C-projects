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

class LineBreakFilter : public FileFilter {
public:
    char transform(char ch) {
        if (ch == '\n' || ch == '\r') {
            return ' '; 
        }
        return ch; 
    }
};

int main() {
    ifstream inputFile("paper.txt");
    ofstream outputFile("paper.txt");

    LineBreakFilter lineBreakFilter;
    lineBreakFilter.doFilter(inputFile, outputFile);

    inputFile.close();
    outputFile.close();

    return 0;
}
