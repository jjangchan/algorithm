//
// Created by jjangchan on 2021-09-23.
// N개의 최소공배수
//

#ifndef ALGORITHM_12953_H
#define ALGORITHM_12953_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <algorithm>

// arr_len은 배열 arr의 길이입니다.
// 유클리드 호제법

int gcd(const int a, const int b){
    return b ? gcd(b, a%b) : a;
}

int lcm(int a, int b){
    if(a < b){
        int temp = a;
        a = b;
        b = temp;
    }
    return (a*b)/gcd(a,b);
}

int solution(int arr[], size_t arr_len) {
    int answer = 0;
    answer = arr[0];
    for(int i = 1; i < arr_len; i++)
        answer = lcm(arr[i], answer);
    return answer;
}

#endif //ALGORITHM_12953_H
