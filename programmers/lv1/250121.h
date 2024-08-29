//
// Created by jjangchan on 2023/12/26.
// PCCE 기출문제 10번 - 데이터 분석
//

#ifndef MAIN_CPP_250121_H
#define MAIN_CPP_250121_H

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    std::map<std::string, int> m;
    m["code"] = 0, m["date"] = 1, m["maximum"] = 2, m["remain"] = 3;
    for(const auto& v : data){
        if(v[m[ext]] < val_ext) answer.push_back(v);
    }
    std::sort(answer.begin(), answer.end(),[&](const auto& a, const auto& b)-> bool{
        return a[m[sort_by]] < b[m[sort_by]];
    });
    return answer;
}

#endif //MAIN_CPP_250121_H
