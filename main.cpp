#include <iostream>
#include <string>
#include "programmers/81301.h"

int main(){
    std::string s = "abcd";
    for(int i = 0; i < 16; i++){
        std::string str = "";
        for(int j = 0; j < 4; j++){
            str += ((i & (1 << j)) ? '-' : s[j]);
        }
        std::cout << str << std::endl;

    }
    return 0;
}