#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<iomanip>

void fileHandling(){
    std::ifstream in_stream;
    std::ofstream out_stream;

    // open the files to read
    // and also write from it
    in_stream.open("infile.dat");
    if(in_stream.fail()){
        std::cout<<"failed to open file"<<std::endl;
        exit(1);
    }
    out_stream.open("outfile.dat");
    if(out_stream.fail()){
        std::cout<<"failed to write to file"<<std::endl;
        exit(1);
    }

    int f, s, t;
    in_stream >> f >> s >> t ;

    // take the sum of the 3 ints
    // populate the outfile.md
    out_stream << "sum of numbers from files.md is\n" << f + s + t;

    // close both open files
    in_stream.close();
    out_stream.close();

    std::cout << "read and write operation successfully \n";
}

int main(){
    fileHandling();
}