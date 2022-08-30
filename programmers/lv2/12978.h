#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 500001

std::vector<int> dijkstra(const int start, const int N, const vector<std::pair<int, int>>* graph){
    std::vector<int> distance(N+1, INF);
    distance[start] = 0;
    std::priority_queue<std::pair<int,int>> q;
    q.push({0, start});
    while(!q.empty()){
        int current_distance = -q.top().first, current_node = q.top().second;
        q.pop();
        for(int i = 0; i < graph[current_node].size(); i++){
            int next_node = graph[current_node][i].first, next_distance = graph[current_node][i].second + current_distance;
            if(next_distance < distance[next_node]){
                distance[next_node] = next_distance;
                q.push({-next_distance, next_node});
            }
        }
    }
    return distance;
}


int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    std::vector<std::pair<int, int>> graph[N+1];
    for(const auto& v : road){
        graph[v[0]].push_back({v[1], v[2]});
        graph[v[1]].push_back({v[0],v[2]});
    }

    for(auto dist : dijkstra(1, N, graph)){
        if(dist <= K) answer++;
    }
    return answer;
}