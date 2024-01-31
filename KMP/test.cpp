#include "LPS.h"
#include <iostream>


int main(int argc, char* argv[]){
    if(argc <= 1){
        std::cout << "Invalid command, expecting <executable> <pattern> (optional)<text>" << std::endl;
        exit(1);
    }

    std::string pattern = argv[1];
    std::string text = argc>2 ? argv[argc-1] : "default text";

    std::cout << "text: " << text << std::endl;
    std::cout << "pattern: " << pattern << std::endl;

    LPS lps = LPS(pattern);

    for(auto x: lps.arr){
        std::cout << x << ", ";
    }
    std::cout << "\n";

    return 0;
}

