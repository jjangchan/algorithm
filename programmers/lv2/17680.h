//
// Created by jjangchan on 2024/08/29.
// 17680 - 캐시
//

#ifndef MAIN_CPP_17680_H
#define MAIN_CPP_17680_H

#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    std::list<std::string> LRU;
    for(std::string& city : cities){
        std::transform(city.begin(), city.end(), city.begin(), ::tolower);
        std::list<std::string>::iterator iter;
        for(iter = LRU.begin(); iter != LRU.end(); ++iter) if(*iter == city) break;
        if(iter == LRU.end()){
            answer += 5;
            if(cacheSize > 0){
                if(LRU.size() >= cacheSize) LRU.pop_front();
                LRU.push_back(city);
            }
        }else{
            answer += 1;
            LRU.erase(iter);
            LRU.push_back(city);
        }
    }
    return answer;
}


#endif //MAIN_CPP_17680_H
