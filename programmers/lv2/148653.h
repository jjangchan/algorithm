//
// Created by jjangchan on 2023/08/06.
// 마법의 엘리베이터 - 148653
//

#ifndef MAIN_CPP_148653_H
#define MAIN_CPP_148653_H

#include <string>
#include <queue>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int storey) {
    std::queue<std::pair<int, int>> q;
    q.push({storey, 0});
    int answer = 0x3f3f3f;

    while(!q.empty()){
        std::pair<int, int> p = q.front();
        q.pop();
        if(p.first <= 1) answer = std::min(answer, p.first+p.second);
        else{
            while(p.first){
                int cnt = p.first%10;
                p.first /= 10;
                if(cnt){
                    std::cout << p.first << "(" << p.second+cnt <<")" << " , ";
                    q.push({p.first, p.second+cnt});
                    std::cout << p.first+1 << "(" << p.second+10-cnt << ")"<< std::endl;
                    q.push({p.first+1, p.second+10-cnt});
                    break;
                }
            }
        }
    }
    std::cout << answer << std::endl;
    return answer;
}

#endif //MAIN_CPP_148653_H
