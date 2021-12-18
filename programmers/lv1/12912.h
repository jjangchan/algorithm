//
// Created by jjangchan on 2021-12-14.
// 두 정수 사이의 합
//

#ifndef MAIN_CPP_12912_H
#define MAIN_CPP_12912_H

/** 비트 연산자 풀이법
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if (a > b) a ^= b ^= a ^= b;
    answer = (long long)b * -~b / 2 - (long long)a * ~-a / 2;
    return answer;
}
**/

#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    long long n = ((a > b) ? a-b : b-a) + 1;
    answer = (n*(a+b))/(long long)2;
    return answer;
}

#endif //MAIN_CPP_12912_H
