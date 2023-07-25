//
// Created by jjangchan on 2023/07/24.
// 169199 - 리코쳇 로봇
//

#ifndef MAIN_CPP_169199_H
#define MAIN_CPP_169199_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

int x[4] = {-1,1,0,0};  // 상, 하, 좌, 우
int y[4] = {0, 0, -1, 1};
int graph[102][102];

using namespace std;

int solution(vector<string> board) {
    std::pair<int, int> start = {0,0}, end = {0,0};
    for(int i = 0; i < board.size(); i++) for(int j = 0; j < board[0].size(); j++){
        graph[i+1][j+1] = 0x3f3f3f3f;
        if(board[i][j] == 'D') graph[i+1][j+1] = 0;
        else if(board[i][j] == 'R') {
            start = {i + 1, j + 1};
            graph[i+1][j+1] = 0;
        }
        else if(board[i][j] == 'G') end = {i+1, j+1};
    }

    auto move = [&](std::pair<int,int>& location, int dict)->std::pair<int, int>{
        std::pair<int, int> xy = {location.first, location.second};
        while(graph[xy.first+x[dict]][xy.second+y[dict]]) {
            xy.first += x[dict], xy.second += y[dict];
        }
        return xy;
    };
    std::queue<std::pair<int,int>> dfs;
    dfs.push(start);
    int i = 0;
    while(!dfs.empty() ){
        std::pair<int ,int> location = dfs.front();
        dfs.pop();
        if(location == end) continue;
        int dis = graph[location.first][location.second]+1, size = dfs.size();
        for(int i = 0; i < 4; i++){
            int next_x = location.first+x[i], next_y = location.second+y[i];
            if(graph[next_x][next_y]){
                std::pair<int, int> move_xy = move(location, i);
                if(dis < graph[move_xy.first][move_xy.second]){
                    graph[move_xy.first][move_xy.second] = dis;
                    dfs.push(move_xy);
                }
            }
        }
        if(dfs.size() > size) graph[location.first][location.second]++;
    }
    return (graph[end.first][end.second] == 0x3f3f3f3f) ? -1 : graph[end.first][end.second];
}

#endif //MAIN_CPP_169199_H
