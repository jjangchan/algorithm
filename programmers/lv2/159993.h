//
// Created by jjangchan on 2023/07/28.
// 미로 탈출 - 159993
//

#ifndef MAIN_CPP_159993_H
#define MAIN_CPP_159993_H

#include <string>
#include <vector>
#include <queue>

using namespace std;

int graph[102][102];
int dx[4] = {0,1,0,-1}; // 우, 하, 좌, 상
int dy[4] = {1,0,-1,0};

int solution(vector<string> maps) {
    auto go = [&](char start, char end)-> int{
        std::queue<std::pair<int ,int>> location; // -- (1)
        for(int i = 0; i < maps.size(); i++) for(int j = 0; j < maps[0].size(); j++){ // -- (2)
                if(maps[i][j] != 'X') graph[i+1][j+1] = 1;
                if(maps[i][j] == end) graph[i+1][j+1] = -1;
                if(maps[i][j] == start) {
                    location.push({i+1, j+1});
                    graph[i+1][j+1] = 1;
                }
        }
        while(!location.empty()){
            std::pair<int, int> xy = location.front();
            location.pop();
            for(int i = 0; i < 4; i++){ // -- (3)
                if(graph[xy.first+dx[i]][xy.second+dy[i]] == -1){ // -- (4)
                    return graph[xy.first][xy.second];
                }
                if(graph[xy.first+dx[i]][xy.second+dy[i]] == 1){ // -- (5)
                    graph[xy.first+dx[i]][xy.second+dy[i]] = graph[xy.first][xy.second]+1; // -- (6)
                    location.push({xy.first+dx[i], xy.second+dy[i]});
                }
            }
            graph[xy.first][xy.second]++; // -- (7)
        }
        return -1;
    };
    int root1 = go('S','L'); // -- (8)
    int root2 = go('L','E');
    return (root1 == -1 || root2 == -1) ? -1 : root1+root2; // -- (9)
}

/**
 * BFS로
 * 시작 -> 레버에 최소 거리를 구하고, 레버 -> 도착에 최소 거리를 구하면 된다.
 * (1) -- 큐로 활용해서 BFS를 구현
 * (2) -- graph 2차 배열에 벽(X)은 0, 시작(S or L)과 통로(O)는 1, 도착(L or E)은 -1로 초기화 한다.
 * (3) -- 큐에 담겨져 있는 좌표(pair<int,int> 를 꺼내 우, 하, 좌, 상을 확인 한다.
 * (4) -- 도착지점(-1)이 있으면 최소거리 이므로 리턴한다.
 * (5) -- 통로는 한번만 접근해야지 최소거리를 구할 수 있으므로 1 인 값만 접근한다.
 * (6) -- 접근한 통로는 현재 좌표 거리+1을 graph 2차배열에 저장하고 -> (지나온 거리에 값들을 저장하기 위해서), 큐에 다음 이동 좌표로 저장한다.
 * (7) -- 큐에서 꺼낸 좌표는 모든 시퀀스를 했으므로 1을 증감해 다시 트래킹할 수 없게 만든다.
 * (8) -- 시작 지점 (S) 에서 레버(L) 까지 최소 거리를 구하고, 레버(L) 에서 도착 지점(E) 까지 최소거리를 구한다.
 * (9) -- 둘 중 하나가 -1이 나오면 길이 없으므로 -1을 리턴하고, 아니면 둘이 합한 거리가 최소거리 이므로 리턴한다.
 */

#endif //MAIN_CPP_159993_H
