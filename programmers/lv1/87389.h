//
// Created by jjangchan on 2021-12-13.
//

#ifndef MAIN_CPP_87389_H
#define MAIN_CPP_87389_H
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    for(int i = 2; i < n; i++) if(n%i == 1) return i;
}

#endif //MAIN_CPP_87389_H
