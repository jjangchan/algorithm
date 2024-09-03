//
// Created by jjangchan on 2024/08/31.
// 17684 - 압축
//

#ifndef MAIN_CPP_17684_H
#define MAIN_CPP_17684_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    std::unordered_map<std::string, int> dict;
    vector<int> answer;
    int cnt = 27;
    for(int i = 0; i < 26; i++) dict[{char('A'+i)}] = i+1;
    for(int i = 0; i < msg.size(); i++){
        std::string val{msg[i]};
        int index = dict[val];
        for(int j = i+1; j < msg.size(); j++){
            val.push_back(msg[j]);
            if(dict.find(val) == dict.end()){
                dict[val] = cnt++;
                break;
            }else index = dict[val], i++;
        }
        answer.push_back(index);
    }
    return answer;
}
#endif //MAIN_CPP_17684_H
