//
// Created by jjangchan on 2024/08/23.
// 42885 - 구명보트
//

#ifndef MAIN_CPP_42885_H
#define MAIN_CPP_42885_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    std::sort(people.begin(), people.end());
    int front = 0, rear = people.size()-1;
    while(front <= rear){
        if(people[rear] + people[front] <= limit) front++, rear--;
        else rear--;
        answer++;
    }
    return answer;
}

#endif //MAIN_CPP_42885_H
