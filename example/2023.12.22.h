//
// Created by jjangchan on 2023/12/20.
//

#ifndef MAIN_CPP_2023_12_22_H
#define MAIN_CPP_2023_12_22_H

#include <iostream>
#include <vector>
#include <queue>

int graph[32][12];

std::vector<int> solution(int n, int k, const std::vector<int>& floors){
    std::vector<int> result;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= k; j++){
        graph[i][j] = 1;
    }

    auto go = [&](const int floor) -> int{
        std::queue<int> bfs;
        bfs.push(floor);
        while(!bfs.empty()){
            int current_floor = bfs.front();
            bfs.pop();
            for(int i = 1; i <= k; i++){
                if(graph[current_floor][i]){
                    graph[current_floor][i] = 0;
                    return current_floor;
                }
            }
            if(current_floor > 1) bfs.push(current_floor-1);
            if(current_floor < n) bfs.push(current_floor+1);
        }
        return 0;
    };

    for(int f : floors) result.push_back(go(f));
    return result;
}

#endif //MAIN_CPP_2023_12_22_H
