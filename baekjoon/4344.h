//
// Created by jjangchan on 2021-11-04.
// 4344 - 평균은 넘겠지
//

#ifndef MAIN_CPP_4344_H
#define MAIN_CPP_4344_H
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>

int N;

std::ostream& operator<<(std::ostream& os, int* arr){
    int sum = 0;
    for(int i = 0; i < N; i++){
        int num;
        scanf("%d", &num);
        sum += num;
        arr[i] = num;
    }
    int average = sum/N;
    double count = 0;
    for(int i = 0; i < N; i++) count = (arr[i] > average) ? count+1 : count;
    double ratio = count/(double)N;
    ratio = (std::round(ratio*100000)/1000.0);
    std::string str_ratio = std::to_string(ratio);
    str_ratio = str_ratio.substr(0, str_ratio.size()-3)+"%";
    os << str_ratio << std::endl;
    return os;
}

void init(){
    int C;
    scanf("%d", &C);
    while(C--){
        scanf("%d", &N);
        int arr[N];
        std::cout << arr;
    }
}

int main(){
    init();
    return 0;
}

#endif //MAIN_CPP_4344_H
