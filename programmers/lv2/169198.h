//
// Created by jjangchan on 2023/07/25.
// 169198 - 당구 연습
//

#ifndef MAIN_CPP_169198_H
#define MAIN_CPP_169198_H

#include <string>
#include <vector>
#include <cmath>

using namespace std;


vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;

    auto same_lien = [&](double base, double height, int a, int b) -> int{
        height = std::min(std::abs(a-height), height);
        int d1 = (int)std::round(std::pow(2.0*std::sqrt(std::pow(base/2.0,2)+std::pow(height,2)),2));
        int d2 = (int)std::pow(base+b*2,2);
        return std::min(d1, d2);
    };
    auto diff_line = [&](int x, int y) -> int{
        int d1 = std::pow(std::abs(startY-y),2) + std::pow(x+startX,2);
        int d2 = std::pow(std::abs(startY-y),2) + std::pow(2*m-startX-x,2);
        int d3 = std::pow(2*n-startY-y, 2) + std::pow(std::abs(startX-x),2);
        int d4 = std::pow(y+startY,2) + std::pow(std::abs(startX-x),2);
        return std::min(std::min(d1,d2), std::min(d3,d4));
    };

    for(const std::vector<int>& ball : balls){
        if(startX == ball[0]){
            answer.push_back(same_lien(std::abs(startY-ball[1]), startX, m, (startY < ball[1]) ? startY : n-startY));
        }else if(startY == ball[1]){
            answer.push_back(same_lien(std::abs(startX-ball[0]), startY, n, (startX < ball[0]) ? startX : m-startX));
        }else{
            answer.push_back(diff_line(ball[0], ball[1]));
        }
    }
    return answer;
}

/**
 * 반사각, 입사각이 동일 조건을 이용해서,
 *  x = 0, y = 0, x = n, y = m 대칭을 이용해서 4개의 대칭 거리에 최솟값을 구한다.
 *
 */

#endif //MAIN_CPP_169198_H
