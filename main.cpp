#include <iostream>
#include <algorithm>
#include "programmers/lv2/67257.h"


void permutaion(bool* is, const std::string& str, const std::string& target){
    if(target.size() == str.size()){
        std::cout << target << std::endl;
    }

    for(int i = 0; i < str.size(); i++){
        if(!is[i]){
            is[i] = true;
            permutaion(is, str, target+str[i]);
            is[i] = false;
        }
    }
}

int main() {
    solution("100-200*300-500+20");
    return 0;
}