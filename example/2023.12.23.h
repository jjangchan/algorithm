//
// Created by jjangchan on 2023/12/21.
//

#ifndef MAIN_CPP_2023_12_23_H
#define MAIN_CPP_2023_12_23_H

#include <iostream>
#include <vector>

int solution(int m, const std::vector<int>& ledger){
    int result = 0;
    for(int i : ledger){
        result = (result+i >= (m*-1)) ? result+i : result;
    }
    return result;
}

#endif //MAIN_CPP_2023_12_23_H
