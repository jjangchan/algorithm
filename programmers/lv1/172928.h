//
// Created by jjangchan on 2023/07/04.
// 공원산책 - 172928
//

#ifndef MAIN_CPP_172928_H
#define MAIN_CPP_172928_H

#include <string>
#include <vector>
#include <map>

using namespace std;
std::map<char, int> location_point = {{'N',0},{'S',1},{'W', 2},{'E',3}};
int xy[2][4] = {{-1, 1, 0, 0},{0, 0, -1, 1}};
int max_x, max_y;
int graph[52][52];

bool is_jump(std::pair<int, int> location, int index, int rou){
    int x = location.first+(xy[0][index]*rou), y = location.second+(xy[1][index]*rou);
    if(x <= 0 || x >= max_x) return false;
    if(y <= 0 || y >= max_y) return false;
    int count = 0, move_x = location.first, move_y = location.second;
    while(count++ < rou){
        move_x += xy[0][index], move_y += xy[1][index];
        if(graph[move_x][move_y]) return false;
        //std::cout << "move >>>>>>>>>>>>> "<< move_x << " , " << move_y << std::endl;
    }
    return true;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    std::pair<int, int> start;
    max_y = park[0].size()+1, max_x = park.size()+1;
    for(int i = 0; i < park.size(); i++) for(int j = 0; j < park[0].size(); j++){
       if(park[i][j] == 'X') graph[i+1][j+1] = 1;
       else if(park[i][j] == 'S') start.first = i+1, start.second = j+1;
    }
    for(std::string& rou : routes){
        int step = rou[2]-'0', index = location_point[rou[0]];
        if(is_jump(start, index, step)){
            start.first += (xy[0][index]*step), start.second += (xy[1][index]*step);
        }
    }
    vector<int> answer = {start.first-1, start.second-1};
    return answer;
}

/**
 * N, S, W, E 방향에 대한 인덱스를 맵으로 매핑하고
 * 매핑된 index에 해당하는 배열로 움직이면서 벽이 있고, 길이를 넘어가는걸 체크한다.
 */

#endif //MAIN_CPP_172928_H
