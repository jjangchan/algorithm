//
// Created by jjangchan on 2023/07/31.
// 154045 - 무인도 여행
//

#ifndef MAIN_CPP_154540_H
#define MAIN_CPP_154540_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int graph[102][102];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<int> solution(vector<string> maps) {
    vector<int> answer;

    for(int i = 0; i< maps.size(); i++) for(int j = 0; j < maps[i].size(); j++){
        if(maps[i][j] != 'X') graph[i+1][j+1] = 1;
    }

    auto dfs = [&](auto& re, const std::pair<int ,int>& location)-> int{
        int result = maps[location.first-1][location.second-1]-'0';
        graph[location.first][location.second] = 0;
        for(int i = 0; i < 4; i++){
           int x = location.first+dx[i], y = location.second+dy[i];
           if(graph[x][y]){
               result += re(re, {x,y});
           }
        }
        return result;
    };

    for(int i = 0; i < maps.size(); i++) {
        for(int j = 0; j < maps[i].size(); j++){
            if(graph[i+1][j+1]){
                answer.emplace_back(dfs(dfs, {i+1, j+1}));
            }
        }
    }


    if((int)answer.size() == 0) return {-1};
    std::sort(answer.begin(), answer.end());
    return answer;
}

#endif //MAIN_CPP_154540_H
