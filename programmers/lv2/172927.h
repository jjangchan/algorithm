//
// Created by jjangchan on 2023/07/20.
// 172927 - 광물 캐기
//

#ifndef MAIN_CPP_172927_H
#define MAIN_CPP_172927_H


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int minerals_source[3][3] = {{1,1,1}, {5,1,1}, {25,5,1}};
std::map<std::string, int> info = {{"diamond", 0}, {"iron",1}, {"stone", 2}};
int is[3];

int work(std::vector<int> &picks, const std::vector<std::string>& minerals){
    int answer = 0, start = 0;
    for(int i = 0; i < minerals.size(); i++){
        if(i%5 == 0 ){
            while(picks[start] <= 0 && start < 3) start++;
            if(start == 3) break;
            picks[start]--;
        }
        answer += minerals_source[start][info[minerals[i]]];
    }
    return answer;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = (1*5)+(5*5)+(25*5);
    std::vector<std::pair<std::string, int>> pair_picks;
    std::sort(picks.begin(), picks.end());
    do{
        std::vector<int> temp;
        for(int i : picks) temp.push_back(i);
        std::cout << work(temp, minerals) << std::endl;
    } while(std::next_permutation(picks.begin(), picks.end()));
    return answer;
}

#endif //MAIN_CPP_172927_H
