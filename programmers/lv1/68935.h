//
// Created by jjangchan on 2021-12-10.
// 3진법 뒤집기
//

#ifndef MAIN_CPP_68935_H
#define MAIN_CPP_68935_H
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int solution(int n) {
    int sum = 0;
    std::vector<int> res;
    while(n){
        res.push_back(n%3);
        n /= 3;
    }
    for(int i = 0; i < res.size(); i++) sum += (pow(3,res.size()-1-i)*res[i]);
    return sum;
}
#endif //MAIN_CPP_68935_H
