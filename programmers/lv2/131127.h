//
// Created by jjangchan on 2023/08/20.
// 할인 행사 - 131127
//

#ifndef MAIN_CPP_131127_H
#define MAIN_CPP_131127_H

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    std::map<std::string ,int> m;
    for(int i = 0; i < 10; i++) m[discount[i]]++;

    for(int i = 0; i <= discount.size()-10; i++){
        int j = 0;
        while(j < want.size()){
            if(m.find(want[j]) == m.end() || m[want[j]] != number[j]) break;
            j++;
        }
        if(j == want.size()) answer++;
        if(i+10 != discount.size()){
            m[discount[i]]--, m[discount[i+10]]++;
        }
    }
    return answer;
}

#endif //MAIN_CPP_131127_H
