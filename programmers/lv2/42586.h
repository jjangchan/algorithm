//
// Created by jjangchan on 2021/12/18.
// 기능개발
//

#ifndef MAIN_CPP_42586_H
#define MAIN_CPP_42586_H

#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    std::queue<int> result_day;
    for(int i =0; i < progresses.size(); i++){
        int rate = progresses[i];
        int speed = speeds[i];
        double day = (100-rate)/speed;
        int i_day = ceil(day);
        result_day.push(i_day);
    }
    std::cout << std::endl;
    int result = result_day.front();
    int count = 1;
    result_day.pop();
    while(!result_day.empty()){
        if(result >= result_day.front()) count++;
        else{
            // initialize data
            answer.push_back(count);
            count = 1;
            result = result_day.front();
        }
        result_day.pop();
    }
    answer.push_back(count);
    return answer;
}

#endif //MAIN_CPP_42586_H
