//
// Created by jjangchan on 2023/09/05.
// 86971 - 전력망을 둘로 나누기
//

#ifndef MAIN_CPP_86971_H
#define MAIN_CPP_86971_H

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    auto dfs = [&](auto& re,std::vector<int>& is, const std::vector<std::vector<int>>& tree,int index)->int{
        int result = 1;
        is[index] = 0;
        for(int i = 0; i < tree[index].size(); i++){
            if(is[tree[index][i]]) result += re(re, is, tree, tree[index][i]);
        }
        return result;
    };

    for(int i = 0; i < wires.size(); i++){
        std::vector<int> is(n+1,1);
        std::vector<std::vector<int>> tree(n+1);
        for(int j = 0; j < wires.size(); j++){
            if(i != j){
                tree[wires[j][0]].push_back(wires[j][1]);
                tree[wires[j][1]].push_back(wires[j][0]);
            }
        }
        int result = 0;
        for(int j = 1; j <= n; j++) if(is[j]) result = std::abs(result - dfs(dfs, is, tree, j));
        answer = std::min(answer, result);
    }
    return answer;
}

#endif //MAIN_CPP_86971_H
