//
// Created by jjangchan on 2023/08/17.
// 택배상자 - 131704
//

#ifndef MAIN_CPP_131704_H
#define MAIN_CPP_131704_H

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    std::stack<int> s;
    for(int i = 1; i <= order.size(); i++){
        s.push(i);
        while(!s.empty() && s.top() == order[answer]){
            answer++, s.pop();
        }
    }
    return answer;
}

#endif //MAIN_CPP_131704_H
