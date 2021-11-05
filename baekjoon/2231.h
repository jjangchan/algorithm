//
// Created by jjangchan on 2021/11/01.
//

#ifndef MAIN_CPP_2231_H
#define MAIN_CPP_2231_H

#include <vector>
#include <iostream>
#include <algorithm>

int Sum(const int N, int a){
    if(N == 0) return a;
    a += (N%10);
    return Sum(N/10, a);
}

int main(){
    int N, result;
    scanf("%d", &N);
    result = N+1;
    for(int i = N; i != 0; i--){
        int cal = i+Sum(i, 0);
        if(cal == N) result = i;
    }
    result = (result == N+1) ? 0 : result;
    std::cout << result << std::endl;
    return 0;
}
#endif //MAIN_CPP_2231_H
