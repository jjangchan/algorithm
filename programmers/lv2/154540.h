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
        if(maps[i][j] != 'X') graph[i+1][j+1] = 1; // -- (1)
    }

    auto dfs = [&](auto& re, const std::pair<int ,int>& location)-> int{
        int result = maps[location.first-1][location.second-1]-'0';
        graph[location.first][location.second] = 0; // -- (3)
        for(int i = 0; i < 4; i++){
           int x = location.first+dx[i], y = location.second+dy[i];
           if(graph[x][y]){
               result += re(re, {x,y}); // -- (4)
           }
        }
        return result; // -- (5)
    };

    for(int i = 0; i < maps.size(); i++) {
        for(int j = 0; j < maps[i].size(); j++){
            if(graph[i+1][j+1]){ // -- (2)
                answer.emplace_back(dfs(dfs, {i+1, j+1})); // -- (6)
            }
        }
    }


    if((int)answer.size() == 0) return {-1};
    std::sort(answer.begin(), answer.end());
    return answer;
}

/**
 * (x,y) 좌표가 이어져 있는 각 자원을 구해야 하므로, DFS로 문제를 해결한다.
 * (1) -- 'X'가 표시 되지 않는 좌표는 접근할 수 있는 경로 이므로 1로 표시
 * (2) -- 해당 maps에 자원(0이 아닌 정수)에 좌표를 접근
 * (3) -- 접근 경로 좌표에 자원값을 구하고, 접근된 좌표는 0 으로 표시해서 다시 백트래킹 못하게 막는다.
 * (4) -- 다음에 접근 경로 좌표를 {우, 하, 좌, 상} 순서로 재귀를 호출 하면서 접근된 값들을 sum 한다.
 * (5) -- 더이상 접근할 수 있는 경로가 없으면 모든 접근 경로에 자원을 sum한 값을 리턴
 * (6) -- 서로 연결된 좌표(무인도)에 자원값을 vector에 저장하고, 다음 무인도를 검색한다.
 */

#endif //MAIN_CPP_154540_H
