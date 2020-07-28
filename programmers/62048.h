//
// Created by JKC on 28/07/2020.
// 62048 - 멀쩡한 사각형
//

#ifndef ALGORITHM_62048_H
#define ALGORITHM_62048_H
using namespace std;

int GCD(int a,int b)
{
    if(a == 0) return b;
    return GCD(b % a,a);
}

long long solution(int w,int h) {
    long long answer = 1;
    long long newW = (long long)w*h;
    int gcd = w+h-GCD(w,h);
    answer= newW-gcd;
    return answer;
}
#endif //ALGORITHM_62048_H
