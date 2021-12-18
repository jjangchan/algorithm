//
// Created by jjangchan on 2021-11-17.
// 67526 - 키패드 누르기
//

#ifndef MAIN_CPP_67526_H
#define MAIN_CPP_67526_H

#include <string>
#include <vector>
#include <cmath>

int Distance(std::pair<int, int>a , std::pair<int, int>b){
    return std::abs(b.first-a.first) + std::abs(b.second-a.second);
}

std::pair<int, int> XY(const int value){
    int x,y;
    if(value == 0) x = 3, y = 1;
    else x = (value-1)/3, y = (value-1)-(x*3);
    return {x,y};
}

char Move(int& location_r, int& location_l, const int destination, const std::string& hand){
    std::pair<int, int> a = XY(destination);
    if(a.second == 0){
        location_l = destination;
        return 'L';
    }else if(a.second == 2){
        location_r = destination;
        return 'R';
    }else{
        std::pair<int, int> b_r = XY(location_r);
        std::pair<int, int> b_l = XY(location_l);
        int distance_r = Distance(b_r, a), distance_l = Distance(b_l, a);
        if(distance_r < distance_l){
            location_r = destination;
            return 'R';
        }else if(distance_l < distance_r){
            location_l = destination;
            return 'L';
        }else{
            if(hand == "right"){
                location_r = destination;
                return 'R';
            }else{
                location_l = destination;
                return 'L';
            }
        }
    }
}

std::string solution(std::vector<int> numbers, std::string hand) {
    std::string answer = "";
    int location_l= 10, location_r = 12;
    for(int i : numbers) answer.push_back(Move(location_r, location_l, i, hand));
    return answer;
}

#endif //MAIN_CPP_67526_H
