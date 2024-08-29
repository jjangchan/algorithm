//
// Created by jjangchan on 2023/12/21.
//

#ifndef MAIN_CPP_2023_12_24_H
#define MAIN_CPP_2023_12_24_H

#include <iostream>

int solution(int N){
    auto go = [](auto& loop, const int k, int num) -> int{
        if(k == 1) return -1;
        if(num < k) return (num == 0) ? 1 : num;
        int cal = (num%k) ? num%k : 1;
        return loop(loop, k, num/k)*cal;
    };
    int result = 0;
    for(int k = 2; k < 10; k++) result = std::max(result, go(go, k, N));
    return result;
}

#endif //MAIN_CPP_2023_12_24_H
