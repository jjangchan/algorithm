//
// Created by jjangchan on 2021-10-07.
// 42576 - 완주하지 못한 선수
//

#ifndef ALGORITHM_42576_H
#define ALGORITHM_42576_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    std::unordered_map<std::string, int> participant_map;
    std::unordered_map<std::string, int> completion_map;
    for(auto iter = participant.begin(); iter != participant.end(); ++iter) participant_map[*iter]++;
    for(auto iter = completion.begin(); iter != completion.end(); ++iter) completion_map[*iter]++;
    for(auto &m : participant_map){
        int completion_count = completion_map[m.first];
        if(m.second != completion_count){
            answer = m.first;
            break;
        }
    }
    return answer;
}

#endif //ALGORITHM_42576_H
