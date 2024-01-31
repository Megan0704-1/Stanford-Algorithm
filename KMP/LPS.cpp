#include "LPS.h"

void LPS::constructArr(){
    int m = pattern.size();
    int prefixLength{0};
    arr = std::vector<int>(m, 0);
    int i{1};

    while(i < m){
        if(pattern[i] == pattern[prefixLength]){
            arr[i++] = ++prefixLength;
        }else{
            if(prefixLength != 0){
                prefixLength = arr[prefixLength-1];
            }else{
                prefixLength = 0;
                arr[i++] = prefixLength;
            }
        }
    }
}
