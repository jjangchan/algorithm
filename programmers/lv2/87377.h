//
// Created by jjangchan on 2024/01/02.
// 87377 - 교점에 별 만들기
//

#ifndef MAIN_CPP_87377_H
#define MAIN_CPP_87377_H

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    long long max_x = -1000000000000, min_x = 1000000000000, max_y = -1000000000000, min_y = 1000000000000;
    std::set<std::pair<long long, long long>> xy;
    for(int i = 0; i < line.size()-1; i++){
        double A = line[i][0], B = line[i][1], E = line[i][2];
        for(int j = i+1; j < line.size(); j++){
            double C = line[j][0], D = line[j][1], F = line[j][2];
            if(A*D-B*C != 0){
                double x = (B*F-E*D)/(A*D-B*C), y = (E*C-A*F)/(A*D-B*C);
                if(std::abs(x-(long long)x) < 1e-12 && std::abs(y-(long long)y) < 1e-12){
                    xy.insert({(long long)x, (long long)y});
                    max_x = std::max(max_x, (long long)x), min_x = std::min(min_x, (long long)x);
                    max_y = std::max(max_y, (long long)y), min_y = std::min(min_y, (long long)y);
                }
            }
        }
    }
    long long w = max_x-min_x+1, h = max_y-min_y+1;
    std::string s(w, '.');
    vector<string> answer(h, s);
    for(const auto& pair : xy) answer[max_y-pair.second][pair.first- min_x] = '*';
    return answer;
}

#endif //MAIN_CPP_87377_H
