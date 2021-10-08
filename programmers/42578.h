//
// Created by jjangchan on 2021-10-08.
// 42578 - 위장
//

#ifndef ALGORITHM_42578_H
#define ALGORITHM_42578_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {

    /** 공식
     * h : (2+(선택안함)) , f : (2+(선택안함)) , a : (2+(선택안함))
     * result = (h(3) * f(3) * a(3)) - (모두 선택 안함) = 27 - 1  = 26
     * */

    int answer = 1;
    std::unordered_map<std::string, int> m;

    /** 시간복잡도
     * 1번) 1(i == 0) + clothes_size(clothes.size-1-0+1) + clothes_size(O(1) + O(1) + *** + O(1)) = 2(close_size)+1
     * 2번) m.size(++iter) + m.size(1(곱하기)+1(더하기)) = 3(m.size)
     * result = 2(close_size)+3(m.size)+1
     * Big-O : O(close_size) + O(m.size)
     */
    for(int i = 0; i < clothes.size(); i++) m[clothes[i][1]]++; // 1번
    for(auto iter = m.begin(); iter != m.end(); ++iter) answer *= (iter->second+1); // 2번
    return answer-1;
}


#endif //ALGORITHM_42578_H
