#ifndef LPS_H
#define LPS_H
#include <vector>
#include <string>

class LPS {
public:
    std::vector<int> arr;
    explicit LPS(const std::string _p): pattern(_p){
        constructArr();
    }
private:
    void constructArr();
    std::string pattern;
};

#endif
