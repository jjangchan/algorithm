//
// Created by jjangchan on 2024/08/23.
// 42883 - 큰 수 만들기
//

#ifndef MAIN_CPP_42883_H
#define MAIN_CPP_42883_H

#include <string>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer;
    char max = number[0];
    int max_index = 0;
    for(int i = 0; i < number.size()-k; i++){
        for(int j = max_index+1; j <= i+k; j++){
           if(max < number[j]){
               max = number[j];
               max_index = j;
           }
        }
        answer.push_back(max);
        std::cout << max << " , " << max_index << std::endl;
        max = number[++max_index];
    }
    return answer;
}

#endif //MAIN_CPP_42883_H
