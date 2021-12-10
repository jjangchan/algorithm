//
// Created by jjangchan on 2021-11-17.
//

#ifndef MAIN_CPP_42748_H
#define MAIN_CPP_42748_H
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto& v : commands){
        std::vector<int> temp;
        for(int i = v[0]-1; i < v[1]; i++)  temp.push_back(array[i]);
        std::sort(temp.begin(), temp.end());
        answer.push_back(temp[v[2]-1]);
    }
    return answer;
}

#endif //MAIN_CPP_42748_H
