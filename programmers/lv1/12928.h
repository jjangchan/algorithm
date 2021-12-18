//
// Created by jjangchan on 2021-12-14.
// 약수의합
//

#ifndef MAIN_CPP_12928_H
#define MAIN_CPP_12928_H

#include <string>
#include <vector>

using namespace std;

int Sum(const int n){
    int sum = n;
    for(int i = 1, end = n >> 1; i <= end; i++) if(n%i == 0) sum+= i;
    return sum;
}

int solution(int n) {
    return Sum(n);
}

#endif //MAIN_CPP_12928_H
