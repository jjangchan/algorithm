//
// Created by jjangchan on 2023/07/19.
// 176962 - 과제 진행하기
//

#ifndef MAIN_CPP_176962_H
#define MAIN_CPP_176962_H

#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int str_to_time(const std::string& str){ // -- (2)
    return stoi(str.substr(0,2))*60+stoi(str.substr(3));
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    std::stack<std::pair<std::string, int>> remaining;
    sort(plans.begin(), plans.end(), [&](const auto& a, const auto& b)->bool{  // -- (1)
        return str_to_time(a[1])< str_to_time(b[1]);
    });

    for(int i = 1; i < plans.size(); i++){
        int next_time = str_to_time(plans[i][1]);
        int current_time = str_to_time(plans[i-1][1]) + stoi(plans[i-1][2]);
        int elapsed_time = next_time-current_time; // -- (3)
        remaining.push({plans[i-1][0], 0});
        while(!remaining.empty()){ // -- (6)
            elapsed_time -= remaining.top().second;
            std::string name = remaining.top().first;
            remaining.pop();
            if(0 > elapsed_time){ // -- (4)
                remaining.push({name, elapsed_time*-1});
                break;
            }else answer.emplace_back(name); // -- (5)
        }
    }
    answer.emplace_back(plans[plans.size()-1][0]);
    while(!remaining.empty()){
        answer.emplace_back(remaining.top().first);
        remaining.pop();
    }
    for(std::string& str : answer) std::cout << str << " ";
    return answer;
}

/**
 * 시간에 순서대로 과제를 진행하고, 다음 시간 순서가 오면 미루고 현재 시간대에 과제를 진행해야 하고,
 * 시간이 남는다면 최근에 미룬 과제를 진행 해야한다. 따라서 문제를 해결 하는데 사용되는 자료구조는
 * 시간에 순서대로 정렬이 필요하고, 시간이 남으면 최근 과제를 먼저 수행하기 때문에 스택이 필요하다. 결론적으로, sort + stack 문제이다.
 *
 * -- (1) 시간 순서대로 오름차순 정렬을 해야하므로, 시간에 정보는 plans 원소([name, start, playtime]) 에 start 에 들어 있으므로,
 *        plans[i][1] 기준으로 정렬 하면 된다.
 * -- (2) start에 type은 string 으로 "00:00" ~ "23:59" 사이의 시간값 이므로, 시와분을 정수값으로 변환하기 위해서 (hour*60)+(minute)
 *        으로 변환해서 리턴해주는 함수를 만든다.
 * -- (3) 정렬된 plans에 i 번째와 i-1번째에 경과된 시간을 측정하기 위해서 인덱스 1부터 루프를 돌면서
 *        str_to_time() 함수를 활용해 elapsed_time 을 구한다.
 * -- (4) 스택에 미리 현재 수행하는 과목(name), 과 경과 시간을 0으로 push 하고, 앞에서 push 된 stack에 내용을 빼고 elapsed_time 가 음수 이면,
 *        현재 과제를 중단하고 다음과제를 해야 하므로, 미룬 과제에 이름, 잔여시간 (name, elapsed_time) 을 스택에 push 한다.
 * -- (5) 양수이면 다음 과제가 시작되기 전에 현재 과제를 끝낼수 있으므로 끝난 과제를 answer에 넣어준다.
 * -- (6) 다음 과제까지 남은 elapsed_time이 계속 양수 이면 스택에 담긴 미룬 과제 처리하기 위해 (5),(4)번 과정을 지속적으로 수행한다.
 *
 */

#endif //MAIN_CPP_176962_H
