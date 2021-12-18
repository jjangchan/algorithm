//
// Created by jjangchan on 2021-12-16.
// 하샤드 수
//

#ifndef MAIN_CPP_12947_H
#define MAIN_CPP_12947_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {
    int temp = x, sum = 0;
    while(temp){
        sum += temp%10;
        temp /= 10;
    }
    return x%sum ? false : true;
}

#endif //MAIN_CPP_12947_H
