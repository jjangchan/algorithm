//
// Created by jjangchan on 2021-12-14.
//

#ifndef MAIN_CPP_12921_H
#define MAIN_CPP_12921_H

#include <string>
#include <vector>
#include <cmath>
#include <memory.h>

using namespace std;
// 에라토스테네스의 체
// 소수의 배수는 소수가 될수 없다.

int solution(int n) {
    int answer = 0;
    bool is_primes[n+1];
    memset(is_primes, false, n+1);
    for(int i = 2; i <= n; i++) {
        if(!is_primes[i]){
            answer++;
            for(int j = 2; j*i <= n; j++) is_primes[j*i] = true;
        }
    }
    return answer;
}

#endif //MAIN_CPP_12921_H
