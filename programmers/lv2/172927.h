//
// Created by jjangchan on 2023/07/20.
// 172927 - 광물 캐기
//

#ifndef MAIN_CPP_172927_H
#define MAIN_CPP_172927_H


#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int minerals_source[3][3] = {{1,1,1}, {5,1,1}, {25,5,1}};
std::map<std::string, int> info = {{"diamond", 0}, {"iron",1}, {"stone", 2}};

int work(const std::vector<std::string>& minerals, int pick_index, int cnt){
    int answer = 0;
    int end = (cnt*5 > minerals.size()) ? (int)minerals.size() : (cnt*5);
    for(int i = (cnt-1)*5; i < end; i++){
        answer += minerals_source[pick_index][info[minerals[i]]];
    }
    return answer;
}

int comb(std::vector<int>& picks,const std::vector<std::string>& minerals, int cnt, int max_size){ // -- (2)
    if(max_size == cnt) {
        for(int p : picks) std::cout << p << " ";
        std::cout<<std::endl;
        return 0;
    }
    int result = 10000;
    for(int i = 0; i < 3; i++){
        if(picks[i] > 0){
            picks[i]--;
            result = std::min(work(minerals, i, cnt+1)+comb(picks, minerals,cnt+1, max_size), result);
            picks[i]++;
        }
    }
    return result;
}


int solution(vector<int> picks, vector<string> minerals) {
    std::vector<std::string> str_picks;
    int count = 0;
    for(int i = 0; i < 3; i++) count += picks[i];
    count = std::min(count, (int)std::ceil((int)minerals.size()/5.0)); // -- (1)
    return comb(picks,minerals, 0,  count);
}

/**
 * 광물 캐기는 곡괭이로 광물을 캘 수 있는 모든 경우의 수를 찾으면 된다. 따라서 DFS로 풀면 해결이 된다.
 * 만약 곡괭이가 (2,2,3) 있고, 광물이 10개 이면,
 * (1) 총 곡쾡이 수는 7개 이고, 1개의 곡괭이는 5개의 광물을 캘 수 있으므로 총 광물에 곡괭이 수는 2(10/5) 개 이다.
 *     따라서, min(총 곡괭이, [총 광물/5]에 올림) 으로 사용할 수 있는 곡괭이 수를 구한다.
 * (2) 재귀로 DFS를 구현해서 사용할 수 있는 곡괭이 수 만큼 곡괭이(다이아몬드, 철, 돌)를 사용하는 모든 경우의 수를 구하면서 피로도에 최솟값을 구한다.
 *
 * [간결한 코드 풀이]
 *
 * unordered_map<string, int> dic[3] = {
    { { "diamond", 1 }, { "iron", 1 }, { "stone", 1 } },
    { { "diamond", 5 }, { "iron", 1 }, { "stone", 1 } },
    { { "diamond", 25 }, { "iron", 5 }, { "stone", 1 } }
};

int solution(vector<int> picks, vector<string> minerals) {
    auto calc = [&](int idx, int tool) -> int {
        int ret = 0;
        for (int i = 0; i < 5 && idx + i < minerals.size(); ++i) ret += dic[tool][minerals[idx + i]];

        return ret;
    };

    auto go = [&](auto& self, int a, int b, int c, int idx = 0) -> int {
        if (a + b + c == 0 || idx >= minerals.size()) return 0;

        int ret = 0x3f3f3f3f;
        if (a) ret = min(ret, calc(idx, 0) + self(self, a - 1, b, c, idx + 5));
        if (b) ret = min(ret, calc(idx, 1) + self(self, a, b - 1, c, idx + 5));
        if (c) ret = min(ret, calc(idx, 2) + self(self, a, b, c - 1, idx + 5));

        return ret;
    };

    return go(go, picks[0], picks[1], picks[2]);
}

 */

#endif //MAIN_CPP_172927_H
