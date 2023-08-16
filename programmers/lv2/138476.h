//
// Created by jjangchan on 2023/08/15.
// 귤 고르기 - 138476
//

#ifndef MAIN_CPP_138476_H
#define MAIN_CPP_138476_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0, sum = 0;
    std::map<int, int>m;
    for(int i : tangerine) m[i]++;
    std::vector<std::pair<int ,int>> v(m.begin(), m.end());
    std::sort(v.begin(), v.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b)->int{
      return a.second > b.second;
    });
    for(const auto& p : v){
        sum += p.second, answer++;
        if(sum >= k) break;
    }
    return answer;
}

#endif //MAIN_CPP_138476_H
