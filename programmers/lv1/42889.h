//
// Created by jjangchan on 2021-12-09.
// 실패율
//

#ifndef MAIN_CPP_42889_H
#define MAIN_CPP_42889_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// if false -> swap
bool compare(std::pair<int, double> a, std::pair<int,double>b){
    // if same, asce
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    std::vector<std::pair<int, double>> pairs;
    std::sort(stages.begin(), stages.end(), greater<int>());
    for(int i = N; i > 0; i--) {
         double a = 0, b = 0;
        for(int stage : stages){
            if(stage < i) break;
            b++;
            if(stage == i)a++;
        }
        double result = (b == 0) ? 0 : a/b;
        pairs.push_back({i, result});
    }
    std::sort(pairs.begin(), pairs.end(), compare);
    for(std::pair<int,double>& p : pairs) answer.push_back(p.first);
    return answer;
}

#endif //MAIN_CPP_42889_H
