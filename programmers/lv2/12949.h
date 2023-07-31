//
// Created by jjangchan on 2021-09-23.
// 행렬의 곱셉
//

#ifndef ALGORITHM_12949_H
#define ALGORITHM_12949_H

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int i = 0; i < arr1.size(); i++){
        vector<int> temp;
        for(int j = 0; j < arr2[0].size(); j++){
            int cal = 0;
            for(int k = 0; k < arr2.size(); k++){
                cal += (arr1[i][k] * arr2[k][j]);
            }
            temp.push_back(cal);
        }
        answer.push_back(temp);
    }
    return answer;
}

#endif //ALGORITHM_12949_H
