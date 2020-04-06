#include "../classes/Student.h"
#include "../classes/BTree.h"

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char** argv) {

    if( argc != 2 ) {

        std::cout << "Incorrect Number of Inputs" << std::endl;
        exit(-1);
    }

    BTree <Student> stuBTree(4);

    std::ifstream dbIn(argv[1]);

    if(!dbIn) {

        std::cout << "Invalid File: " << argv[1] << std::endl;
        exit(-1);
    }

    while (!dbIn.eof()) {

        std::string inLine;
        std::getline(dbIn, inLine);
        std::stringstream lineSS(inLine);

        std::string token;
        std::getline(lineSS, token, ",");
        unsigned int ID = atoi (token.c_str() );

        std::string first;
        std::getline(lineSS, first, ",");

        std::string last;
        std::getline(lineSS, last, ',');

        std::string email;
        std::getline(lineSS, email, ",");

        std::string stuMajor;
        std::getline(lineSS, stuMajor, ",");

        Student tempStu(ID, first, last, email, stuMajor);

        stuBTree.insert( tempStu );
    }

    Student seekVal;
    seekVal.setID(86);
    stuBTree.printFoundNodes( seekVal );
    std::cout << "----------" << std::endl;
    seekVal.setID(10);
    stuBTree.printFoundNodes( seekVal );

    dbIn.close();

    return 0;
}
