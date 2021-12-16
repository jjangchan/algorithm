//
// Created by jjangchan on 2021-12-16.
// 행렬의 덧셈
//

#ifndef MAIN_CPP_12950_H
#define MAIN_CPP_12950_H

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int r = 0; r < arr1.size(); r++){
        std::vector<int> sums;
        for(int l = 0; l < arr1[r].size(); l++){
            sums.push_back(arr1[r][l]+arr2[r][l]);
        }
        answer.push_back(sums);
    }
    return answer;
}

#endif //MAIN_CPP_12950_H
