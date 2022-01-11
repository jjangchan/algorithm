//
// Created by jjangchan on 2021/12/30.
// 거리두기 확인하기
//

#ifndef MAIN_CPP_81302_H
#define MAIN_CPP_81302_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Distance(std::pair<int, int>a, std::pair<int, int> b){
    return std::abs(a.first-b.first) + std::abs(a.second-b.second);
}

template <size_t x, size_t y>
bool CheckEmpty(const int (&empty)[x][y], const std::pair<int, int>& a, const std::pair<int, int>& b){
    int start = a.second, end = b.second;
    if(a.second > b.second) start = b.second, end = a.second;
    for(int i = a.first; i <= b.first; i++) for(int j = start; j <= end; j++){
            if(empty[i][j]) return true;
    }
    return false;
}

template <size_t x, size_t y, size_t z>
bool KeepDistance(const int (&empty)[x][y], const std::vector<int> (&graph)[z],const std::pair<int, int>& location, const int x_start, const int y_start){
    if(location.first+3 <= x_start || x_start >= x) return true;
    for(int i = y_start; i < graph[x_start].size(); i++){
        int distance = Distance(location, {x_start, graph[x_start][i]});
        if(distance >= 3) continue;
        else if(distance == 1 || CheckEmpty(empty, location, {x_start, graph[x_start][i]})) return false;
    }
    return KeepDistance(empty, graph, location, x_start+1, 0);
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for(auto &v : places) {
        int empty[5][5] = {false, };
        std::vector<int> graph[5];
        for(int i = 0; i < v.size(); i++) for(int j = 0; j < v[0].size(); j++){
                if(v[i][j] == 'P') graph[i].push_back(j);
                else if(v[i][j] == 'O') empty[i][j] = true;
            }
        bool is = true;
        for(int x = 0; x < 5 && is; x++) for(int y = 0; y < graph[x].size() && is; y++){
                is = KeepDistance(empty, graph, {x, graph[x][y]},  x, y+1);
            }
        answer.push_back(is);
    }
    return answer;
}

#endif //MAIN_CPP_81302_H
