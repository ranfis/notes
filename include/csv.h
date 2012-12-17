#include <iostream>
#include <string>
#include <fstream>
#include <cstdarg>

typedef unsigned int uint;
using namespace std;
class CSV
{
public:
    ifstream ifs;
    ofstream ofs;
    char* file;
    CSV(char*);
    string read_line(uint);
    string read_data(uint,uint);
    void write_line(uint,bool,char*, ...);
    string read_file();
    void clean();
    void write(char*);
};
