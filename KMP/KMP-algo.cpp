#include "LPS.h"
#include <iostream>

std::vector<int> KMP(const std::string text, 
                     const std::string pattern,
                     const std::vector<int> lps){
    int n = text.size();
    int m = pattern.size();
    int text_ptr{0};
    int pattern_ptr{0};
    std::vector<int> match_;

    while(text_ptr < n){
        if(text[text_ptr] == pattern[pattern_ptr]){
            text_ptr++;
            pattern_ptr++;
        }

        if(pattern_ptr == m){
            match_.push_back(text_ptr-pattern_ptr);
            pattern_ptr = lps[pattern_ptr-1];
        }else if(text_ptr < n && text[text_ptr] != pattern[pattern_ptr]){
            if(pattern_ptr != 0){
                pattern_ptr = lps[pattern_ptr-1];
            }else text_ptr ++;
        }
    }
    return match_;
}

int main(int argc, char* argv[]){
    if(argc <= 1){
        std::cout << "Invalid command, expecting <executable> <pattern> (optional <text>)" << std::endl;
        exit(1);
    }

    std::string text = argc > 2 ? argv[argc-1] : "defualt text";
    std::string pattern = argv[1];

    std::cout << "text: " << text << std::endl;
    std::cout << "pattern: " << pattern << std::endl;

    LPS lps = LPS(pattern);

    if(argc==2){
        for(auto x: lps.arr){
            std::cout << x << ", ";
        }
        std::cout << "\n";
    }

    std::vector<int> matches = KMP(text, pattern, lps.arr);

    for(auto match: matches){
        std::cout << "find pattern at: " << match << "\n";
    }

    return 0;
}
