//
// Created by jjangchan on 2023/12/27.
// PCCP 기출문제 2번 - 석유 시추
//

#ifndef MAIN_CPP_250136_H
#define MAIN_CPP_250136_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land) {
    int n = land.size(), m = land[0].size();
    std::vector<int> result(m, 0);
    int dm[4] = {1, -1, 0, 0};
    int dn[4] = {0, 0, 1, -1};

    auto go = [&](auto& dfs, std::vector<int>& is, const std::pair<int, int>& location) -> int{
        int count = 1;
        land[location.first][location.second] = 0;
        is[location.second] = 1;
        for(int i = 0; i < 4; i++){
            int l_m = location.second+dm[i], l_n = location.first+dn[i];
            if(l_m < 0 || l_m >= m || l_n < 0 || l_n >= n) continue;
            if(land[l_n][l_m]) count += dfs(dfs, is, {l_n, l_m});
        }
        return count;
    };

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        if(land[i][j]){
            std::vector<int> is(m, 0);
            int count = go(go, is, {i, j});
            for(int k = 0; k < m; k++){
                if(is[k]) result[k] += count;
            }
        }
    }
    return *std::max_element(result.begin(), result.end());
}

#endif //MAIN_CPP_250136_H
