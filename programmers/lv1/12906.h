//
// Created by jjangchan on 2021-12-13.
//

#ifndef MAIN_CPP_12906_H
#define MAIN_CPP_12906_H
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    std::vector<int> answer;
    std::vector<int>::iterator iter;
    for(iter = arr.begin()+1; iter != arr.end(); ++iter){
        if(*iter != *(iter-1)) answer.push_back(*(iter-1));
    }
    answer.push_back(*(iter-1));
    return answer;
}

#endif //MAIN_CPP_12906_H
