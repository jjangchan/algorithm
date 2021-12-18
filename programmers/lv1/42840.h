//
// Created by jjangchan on 2021-11-17.
// 42840 - 모의고사
//

#ifndef MAIN_CPP_42840_H
#define MAIN_CPP_42840_H

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    std::vector<int> result[3] = {{1,2,3,4,5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5}};
    std::vector<int> answer;
    int scores[3] = {0,0,0};
    for(int i = 0; i < answers.size(); i++) for(int j = 0; j < 3; j++)
        if(answers[i] == result[j][i%result[j].size()]) scores[j]++;
    int max = 0;
    for(int i = 0; i < 3; i++) max = std::max(max,scores[i]);
    for(int i = 0; i < 3; i++) if(scores[i] > 0 && scores[i] == max) answer.push_back(i+1);
    return answer;
}

#endif //MAIN_CPP_42840_H
