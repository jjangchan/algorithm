//
// Created by jjangchan on 2021-09-23.
// 피보나치 수
//

#ifndef ALGORITHM_12945_H
#define ALGORITHM_12945_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int fibonacci(const int n){
    int a = 0;
    int b = 1;
    for(int i = 1; i < n; i++){
        int temp = a;
        a = b;
        b += temp;
        b %= 1234567;
    }
    return b;
}

int solution(int n) {
    int answer = fibonacci(n);
    return answer;
}

#endif //ALGORITHM_12945_H
