//
// Created by jjangchan on 2021-12-10.
// 두 개 뽑아서 더하기
//

#ifndef MAIN_CPP_68644_H
#define MAIN_CPP_68644_H
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


vector<int> solution(vector<int> numbers) {
    std::set<int> sums;
    for(int i = 0; i< numbers.size(); i++)for(int j = i+1; j < numbers.size(); j++){
            sums.insert(numbers[i]+numbers[j]);
    }
    vector<int> answer(sums.begin(), sums.end());
    return answer;
}

#endif //MAIN_CPP_68644_H
