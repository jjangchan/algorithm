//
// Created by jjangchan on 2023/07/11.
// 요격 시스템
//

#ifndef MAIN_CPP_181188_H
#define MAIN_CPP_181188_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(vector<vector<int>> targets) {
    int answer = 0;
    std::sort(targets.begin(), targets.end(), [](std::vector<int>& a, std::vector<int>& b)->bool{
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });
    int i = 0;
    while(i < targets.size()){
        int j, y = targets[i][1];
        std::cout << "in...." << std::endl;
        for(j = i+1; j < targets.size(); j++){
            if(targets[i][0] < targets[j][0] && y <= targets[j][0]) break;
            if(targets[j][1] < y) y = targets[j][1];
        }
        i = j;
        answer++;
    }
    return answer;
}

/***
 * 개구간 (s, e)를 s 오름차순, 만약 s가 같다면 e 오름차순으로 정렬한다.
 * 정렬된 구간 i(s,e) < x(s,e) < j(s,e) 에서 구간 x(s,e)에 요격 조건은
 * (1) x(s) 는 i(s) 보다 같거나 크고 j(s) 보다 작아야 하고,
 * (2) x(e) 는 j(s) 보다 작아야 하고 i(e) 보다 같거나 커야 한다.
 */

#endif //MAIN_CPP_181188_H
