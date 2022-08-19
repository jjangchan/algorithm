//
// Created by jjangchan on 2022/08/19.
// 예상 대진표
//

#ifndef MAIN_CPP_12985_H
#define MAIN_CPP_12985_H

#include <iostream>

using namespace std;

int cal(const int& num){
    return (num&1) ? (num+1) - (num+1)/2 : num - num/2;
}

int solution(int n, int a, int b)
{
    int answer = 0;
    while(a != b){
        a = cal(a);
        b = cal(b);
        answer++;
    }
    return answer;
}

#endif //MAIN_CPP_12985_H
