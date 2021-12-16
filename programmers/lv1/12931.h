//
// Created by jjangchan on 2021-12-16.
// 자릿수 더하기
//

#ifndef MAIN_CPP_12931_H
#define MAIN_CPP_12931_H

#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    while(n){
        answer += (n%10);
        n /= 10;
    }
    return answer;
}

#endif //MAIN_CPP_12931_H
