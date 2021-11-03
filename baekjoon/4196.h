//
// Created by jjangchan on 2021-11-01.
//

#ifndef MAIN_CPP_4196_H
#define MAIN_CPP_4196_H
#include <vector>
#include <iostream>
#include <algorithm>

void RDFS(std::vector<int> *nodes, bool *visited, const int to, std::vector<int>& scc){
    visited[to] = true;
    scc.push_back(to);
    for(int i = 0; i < nodes[to].size(); i++){
        int index = nodes[to][i];
        if(!visited[index]) RDFS(nodes, visited, index, scc);
    }
}

void DFS(std::vector<int> *nodes, bool *visited, int *arr, const int to, int& time){
    visited[to] = true;
    for(int i = 0; i < nodes[to].size(); i++){
        int index = nodes[to][i];
        if(!visited[index]) DFS(nodes, visited, arr, index, time);
    }
    arr[++time] = to;
}

void DFS(std::vector<int> *nodes, bool *visited, const int to){
    visited[to] = true;
    for(int i = 0; i < nodes[to].size(); i++){
        int index = nodes[to][i];
        if(!visited[index]) DFS(nodes, visited, index);
    }
}

template <typename T>
void Reset(T *t, const T value, int size){
    while(--size != -1) t[size] = value;
}

int main(){

    int loop_count, N, M;
    scanf("%d", &loop_count);
    while(loop_count--){
        scanf("%d %d",&N, &M);
        if(M == 0){
            std::cout << N << std::endl;
            continue;
        }
        std::vector<int> nodes[N+1];
        std::vector<int> reverse_nodes[N+1];
        bool visited[N+1];
        int arr[N+1];
        Reset(visited, false, N+1);
        while(M--){
            int from, to;
            scanf("%d %d",&from, &to);
            nodes[from].push_back(to);
            reverse_nodes[to].push_back(from);
        }
        int time = 0;
        for(int i = 1; i <= N; i++){
            if(!visited[i])DFS(nodes, visited, arr, i, time);
        }
        Reset(visited, false, N+1);
        std::vector<std::vector<int>> scc;
        for(int i = N; i >= 1; i--){
            if(!visited[arr[i]]){
                std::vector<int> in_scc;
                RDFS(reverse_nodes, visited, arr[i], in_scc);
                scc.push_back(in_scc);
            }
        }
        Reset(visited, false, N+1);
        int result = 0;
        for(auto &v : scc)for(int i : v){
                if(!visited[i]){
                    DFS(nodes, visited, i);
                    result++;
                }
            }
        std::cout << result << std::endl;
    }
    return 0;
}

#endif //MAIN_CPP_4196_H
