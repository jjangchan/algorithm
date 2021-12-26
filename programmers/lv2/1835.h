//
// Created by jjanchan on 2021-12-24.
// 단체사진 찍기
//

#ifndef MAIN_CPP_1835_H
#define MAIN_CPP_1835_H

#include <string>
#include <vector>

using namespace std;

void Combination(bool* is, const std::string& str, const int end, const std::string& temp, int& count){
    if(temp.size() == end){
        std::cout << temp << std::endl;
        count++;
        return;
    }
    for(int i = 0; i < end; i++){
        if(!is[i]){
            is[i] = true;
            Combination(is, str, end, temp+str[i], count);
            is[i] = false;
        }
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    std::string str = "ABCD";
    bool is[4] = {false,};
    int count = 0;
    Combination(is, str, 4, "", count);
    std::cout << count;
    return answer;
}


#endif //MAIN_CPP_1835_H
