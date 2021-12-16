//
// Created by jjangchan on 2021-12-16.
// 최대공약수와 최소공배수
//

#ifndef MAIN_CPP_12940_H
#define MAIN_CPP_12940_H
#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b){
    return a%b ? GCD(b, a%b) : b;
}

vector<int> solution(int n, int m) {
    vector<int> answer(2);
    int a = n > m ? n : m;
    int b = n > m ? m : n;
    int gcd = GCD(a,b);
    answer[0] = gcd;
    answer[1] = a*b/gcd;
    return answer;
}

#endif //MAIN_CPP_12940_H
