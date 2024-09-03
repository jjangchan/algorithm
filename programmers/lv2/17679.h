//
// Created by jjangchan on 2024/08/29.
// 17679 - 프렌즈4블록
//

#ifndef MAIN_CPP_17679_H
#define MAIN_CPP_17679_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int drop(std::vector<std::string>& board, int x, const int y, const int m){
    if(x+1 == m) return 0;
    return board[x+1][y] != '0' ? 0 : drop(board, x+1, y, m)+1;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while(true){
        std::vector<std::pair<int,int>> hits;
        for(int i = 0; i < m-1; i++) for(int j = 0; j < n-1; j++){
                if(board[i][j] == '0') continue;
                if(board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j] && board[i][j] == board[i+1][j+1]) hits.push_back({i, j});
        }
        if(hits.empty()) break;
        std::vector<bool> drop_y(n, false);
        for(const auto& hit : hits){
            int x = hit.first, y = hit.second;
            board[x][y] = '0', board[x][y+1] = '0', board[x+1][y] = '0', board[x+1][y+1] = '0';
            drop_y[y] = true, drop_y[y+1] = true;
        }
        for(int y = 0; y < n; y++){
            if(drop_y[y]){
                for(int x = m-2; x >= 0; x--){
                    if(board[x][y] != '0') {
                        int jump = drop(board, x, y, m);
                        if(jump) board[x+jump][y] = board[x][y], board[x][y] = '0';
                    }
                }
            }
        }
    }

    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) if(board[i][j] == '0') answer++;
    return answer;
}

#endif //MAIN_CPP_17679_H
