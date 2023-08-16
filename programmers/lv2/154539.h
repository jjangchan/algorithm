//
// Created by jjangchan on 2023/07/31.
// 뒤에 있는 큰 수 찾기 - 154539
//

#ifndef MAIN_CPP_154539_H
#define MAIN_CPP_154539_H

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    std::stack<int> temp;

    for(int i = 0; i < numbers.size(); i++){
        while(!temp.empty() && numbers[temp.top()] < numbers[i]){ // -- (3)
            answer[temp.top()] = numbers[i]; // -- (2)
            temp.pop();
        }
        temp.push(i); // -- (1)
    }
    return answer;
}

/**
 * 문제를 읽어 보면 '가장 가까이 있는 수' 라는 문장을 보면서 스택문제 라는걸 캡치한다. 왜냐하면,
 * 정수들에 인덱스를 스택에 쌓고 최근 값중에 뒷 큰수가 있으면 stack을 pop해서 값을 넣어주면 인덱스 위치를 보장하면서 큰수를 넣을수 있다.
 *
 * (1) -- for문을 돌면서 현재 index를 스택에 푸쉬
 * (2) -- 스택 탑 값중에 현재 정수보다 큰값이 있으면 스택 탑 인덱스에 큰 정수값을 넣어주고, pop 한다
 * (3) -- 스택에 값이 있으면 다음 값이 (2)번 과정을 while() 문으로 계속 검증
 */

#endif //MAIN_CPP_154539_H
