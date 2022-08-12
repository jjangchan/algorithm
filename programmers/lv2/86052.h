//
// Created by jjangchan on 2022/08/12.
// 빛의 경로 사이클
//

/** best solution
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool is_visit[500][500][4];

vector<int> solution(vector<string> grid) {
    int dir[4][2] = {{0,1}, {-1,0}, {0,-1}, {1,0}};
    vector<int> answer;
    for (int i=0; i<4; i++)
        for (int j=0; j<grid.size(); j++)
            for (int k=0; k<grid[0].size(); k++)
                if (is_visit[j][k][i] == false)
                {
                    int r=j, c=k, d=i, l=1;
                    is_visit[j][k][i] = true;
                    while(1)
                    {
                        if (grid[r][c]== 'L') d = (d+1)%4;
                        else if (grid[r][c] == 'R') d = (4+d-1)%4;
                        r = (grid.size() + r + dir[d][0])%grid.size();
                        c = (grid[0].size() + c + dir[d][1])%grid[0].size();
                        if (is_visit[r][c][d]) break;
                        is_visit[r][c][d] = true;
                        l++;
                    }
                    answer.push_back(l);
                }
    sort(answer.begin(), answer.end());
    return answer;
}
 **/

#ifndef MAIN_CPP_86052_H
#define MAIN_CPP_86052_H

#include <string>
#include <vector>
#include <algorithm>

// 0 -> (in)left, 1 -> (in)right, 2 -> (in)up, 3 -> (in)down
std::vector<std::pair<int,int>> s_direction = {{0,1}, {0, -1}, {1,0}, {-1, 0}};
std::vector<std::pair<int,int>> l_direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
std::vector<std::pair<int,int>> r_direction = {{1,0}, {-1,0}, {0, -1}, {0, 1}};
int is_search[500][500][4];
int max_row, max_col;

int index_to_direction(const int cal){
    switch (cal) {
        case 2: return 0;
        case -2: return 1;
        case 1: return 2;
        case -1: return 3;
    }
    return -1;
}

std::vector<int> solution(std::vector<std::string> grid) {
    std::vector<int> answer;
    max_row = grid.size(), max_col = grid[0].size();
    for(int r = 0; r < max_row; r++){
        for(int c = 0; c < max_col; c++){
            for(int i = 0; i < 4; i++){
                if(is_search[r][c][i] >= 1) continue;
                int count = 0;
                std::pair<int, int> index = {r+s_direction[i].first, c+s_direction[i].second};
                int move_index = index_to_direction((s_direction[i].first*1)+(s_direction[i].second*2));
                is_search[r][c][i]++;
                while(true){
                    if(is_search[r][c][i] >= 2) break;
                    //------ out range
                    if(index.second < 0 || index.second >= max_col) index.second = (index.second < 0) ? max_col-1 : 0;
                    else if(index.first < 0 || index.first >= max_row) index.first = (index.first < 0) ? max_row-1 : 0;
                    //------
                    char direction = grid[index.first][index.second];
                    std::pair<int,int> d_move = ((direction == 'S') ? s_direction[move_index] : (direction == 'R') ? r_direction[move_index] : l_direction[move_index]);
                    move_index = index_to_direction((d_move.first*1)+(d_move.second*2));
                    is_search[index.first][index.second][move_index]++;
                    index.first += d_move.first, index.second += d_move.second;
                    count++;
                }
                answer.push_back(count);
            }
        }
    }
    std::sort(answer.begin(), answer.end());
    return answer;
}

#endif //MAIN_CPP_86052_H
