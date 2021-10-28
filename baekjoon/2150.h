//
// Created by jjangchan on 2021-10-27.
//

#ifndef MAIN_CPP_2150_H
#define MAIN_CPP_2150_H
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 100001
std::vector<int> node[MAX];
std::vector<int> reverse_node[MAX];
bool visited[MAX];

void DFS(const int index, int &current_time, int *ft){
    visited[index] = true;
    for(int i = 0; i < node[index].size(); i++){
        if(!visited[node[index][i]]) DFS(node[index][i], current_time, ft);
    }
    ft[current_time++] = index;
}

void RDFS(std::vector<int> &v, const int index){
    visited[index] = true;
    v.push_back(index);
    for(int i = 0; i < reverse_node[index].size(); i++){
        if(!visited[reverse_node[index][i]]) RDFS(v, reverse_node[index][i]);
    }
}

template <typename T>
void Reset(T* t, T value, const int size){
    for(int i = 0; i < size/sizeof(T); i++)
        t[i] = value;
}

int main(){
    int V= 0, E = 0;
    scanf("%d %d", &V, &E);
    int to, from;
    while(E--){
        scanf("%d %d", &from, &to);
        node[from].push_back(to);
        reverse_node[to].push_back(from);
    }
    int ft[MAX];
    std::vector<std::vector<int>> scc;
    Reset(ft, -1, sizeof(ft));
    Reset(visited, false, sizeof(visited));
    int current_time = 1;
    for(int i = 1; i <= V; i++){
        if(!visited[i]) DFS(i, current_time, ft);
    }
    Reset(visited, false, sizeof(visited));
    for(int i = V; i >= 1; i--){
        int index = ft[i];
        if(index == -1) continue;
        if(!visited[index]){
            std::vector<int> v;
            RDFS(v, index);
            std::sort(v.begin(), v.end());
            scc.push_back(v);
        }
    }
    std::sort(scc.begin(), scc.end());
    std::cout << scc.size() << std::endl;
    for(std::vector<int> &v : scc){
        for(int i : v){
            std::cout << i << " ";
        }
        std::cout << "-1" << std::endl;
    }

    return 0;
}


#endif //MAIN_CPP_2150_H
