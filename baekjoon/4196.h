//
// Created by jjangchan on 2021-11-01.
//

#ifndef MAIN_CPP_4196_H
#define MAIN_CPP_4196_H
#include <vector>
#include <iostream>
#include <algorithm>

void RDFS(std::vector<int> *nodes, bool *r_visited, bool *visited, int *arr, const int to, const int parent){
    r_visited[to] = true, arr[to] = parent;
    for(int i = 0; i < nodes[to].size(); i++){
        int index = nodes[to][i];
        if(visited[index] && !r_visited[index]){
            //std::cout << "reverse : " << index << std::endl;
            RDFS(nodes, r_visited, visited, arr, index, parent);
        }
    }
}

void DFS(std::vector<int> *nodes, bool *done, bool *visited, int *arr, const int to, const int parent){
    visited[to] = true, done[to] = true, arr[to] = parent;
    int index;
    for(int i = 0; i < nodes[to].size(); i++){
        index = nodes[to][i];
        if(!visited[index]){
            DFS(nodes, done, visited, arr, index, parent);
        }
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
        bool visited[N+1], r_visited[N+1], done[N+1];
        int arr[N+1];
        Reset(done, false, N+1);
        while(M--){
            int to, from;
            scanf("%d %d",&to, &from);
            nodes[to].push_back(from);
            reverse_nodes[from].push_back(to);
        }
        for(int i = 1; i <= N; i++){
            if(!done[i]){
                Reset(visited, false, N+1);
                DFS(nodes, done, visited, arr, i, i);
                RDFS(reverse_nodes,r_visited, visited, arr, i, i);
            }
        }
        int result = 0;
        Reset(done, false, N+1);
        for(int i =1; i <= N; i++){
            if(!done[arr[i]]){
                result++;
                done[arr[i]] = true;
            }
        }
        std::cout << result << std::endl;
    }
    return 0;
}

#endif //MAIN_CPP_4196_H
