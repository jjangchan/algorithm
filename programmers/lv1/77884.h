//
// Created by jjangchan on 2021-12-10.
// 약수의 개수와 덧셈
//

#ifndef MAIN_CPP_77884_H
#define MAIN_CPP_77884_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;
/** 비트 연산자 풀이법, 신기해서 가져옴
int sign(int n, int count = 1) {
    for (int i = 1, last = n >> 1; i <= last; ++i) if (n % i == 0) ++count;
    return count & 1 ? -1 : 1;
}
int solution(int a, int b) { return a > b ? 0 : sign(a)*a + solution(a + 1, b); }
**/

int Divisor(const int size, const int target){
    if(target <= 2) return target == 1 ? 1 : 2;
    int count = 2;
    int index = 1;
    while(index++ <= size) if(target%index == 0) count++;
    return count;
}

int solution(int left, int right) {
    int answer = 0;
    for(int i = left; i <= right; i++){
        int count = Divisor(i/2,i);
        answer += ((count%2) ? i*-1 : i);
    }
    return answer;
}

#endif //MAIN_CPP_77884_H
