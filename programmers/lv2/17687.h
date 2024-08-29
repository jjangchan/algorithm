//
// Created by jjangchan on 2024/08/29.
// 17687 - n 진수 게임
//

#ifndef MAIN_CPP_17687_H
#define MAIN_CPP_17687_H

#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer;
    int num = 0, index = 1;
    while(answer.size() < t){
        std::string str;
        int cal = num;
        while(true){
            int s = cal%n;
            (s < 10) ? str.push_back('0'+s) : str.push_back('A'+(s-10));
            cal /= n;
            if(cal == 0) break;
        }
        for(long long i = (long long)str.size()-1; i >= 0; i--){
            if(index%p == 0 && answer.size() < t){
                answer.push_back(str[i]);
                p += m;
            }
            index++;
        }
        num++;
    }
    return answer;
}

#endif //MAIN_CPP_17687_H
