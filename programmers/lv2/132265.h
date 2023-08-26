//
// Created by jjangchan on 2023/08/16.
// 롤케이크 자르기 - 132265
//

#ifndef MAIN_CPP_132265_H
#define MAIN_CPP_132265_H

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int is_left[10001], is_right[10001];

int solution(vector<int> topping) {
    int answer = 0;
    std::set<int> l, r;
    is_left[topping[0]]++;
    l.insert(topping[0]);
    for(int i = 1; i < topping.size(); i++){
        if(is_right[topping[i]] == 0) r.insert(topping[i]);
        is_right[topping[i]]++;
    }

    for(int i = 1; i < topping.size(); i++){
        if(l.size() == r.size()) answer++;
        l.insert(topping[i]);
        is_right[topping[i]]--;
        if(is_right[topping[i]] == 0) r.erase(topping[i]);
    }
    return answer;
}

#endif //MAIN_CPP_132265_H
