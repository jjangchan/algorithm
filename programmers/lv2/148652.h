//
// Created by jjangchan on 2023/08/08.
// 유사 칸토어 비트열
//

#ifndef MAIN_CPP_148652_H
#define MAIN_CPP_148652_H

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, long long l, long long r) {
    long long answer = (r-l)+1;
    while(l <= r){
        for(int i = 1; i <= n; i++){
            long long p1 = (long long)std::pow(5, i), p2 = (long long)std::pow(5, i-1);
            long long x = (l%p1)? l%p1 : p1, a = (p2*2)+1;
            if(a <= x && x < a+p2){
                answer--;
                break;
            }
        }
        l++;
    }
    return answer;
}

#endif //MAIN_CPP_148652_H
