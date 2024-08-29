//
// Created by jjangchan on 2024/01/09.
// 258711 - 도넛과 막대 그래프
//

#ifndef MAIN_CPP_258711_H
#define MAIN_CPP_258711_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> solution(vector<vector<int>> edges) {
    std::vector<std::vector<int>> graph(1000001);
    std::vector<int> in_out_degree(1000001, 0);

    int length = 0;
    for(const auto& v : edges){
        length = std::max(length, std::max(v[0], v[1]));
        graph[v[0]].push_back(v[1]);
        in_out_degree[v[0]]++, in_out_degree[v[1]]--;
    }
    int start = max_element(in_out_degree.begin(), in_out_degree.begin()+length+1)-in_out_degree.begin();
    int ring = 0, stick = 0, eight = 0;
    std::vector<int> is(length+1, 0);

    auto go = [&](auto& loop, int index, int& edge_cnt, int& node_cnt)-> void{
        edge_cnt += graph[index].size(), node_cnt++;
        is[index] = 1;
        for(int i = 0; i < graph[index].size(); i++){
            if(!is[graph[index][i]]) loop(loop, graph[index][i], edge_cnt, node_cnt);
        }
    };

    for(int i = 0; i < graph[start].size(); i++){
        int edge_cnt = 0, node_cnt = 0;
        go(go , graph[start][i], edge_cnt, node_cnt);
        if(node_cnt-1 == edge_cnt) stick++;
        else if(node_cnt == edge_cnt) ring++;
        else eight++;
    }
    return {start, ring, stick, eight};
}

#endif //MAIN_CPP_258711_H
