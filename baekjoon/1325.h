//
// Created by jjangchan on 2021-10-26.
//

#ifndef MAIN_CPP_1325_H
#define MAIN_CPP_1325_H
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>

const int MAX = 10001;
std::vector<int> node[MAX];

void SearchNode(bool *is, const int key, int& count){
    if(node[key].empty()) return;
    for(int i = 0; i < node[key].size(); i++){
        if(!is[node[key][i]]){
            is[node[key][i]] = true;
            count++;
            SearchNode(is, node[key][i], count);
        }
    }
}

int main(){
    int n, m;
    scanf("%d %d",&n, &m);
    int arr_m[m];
    for(int i = 0; i < m; i++){
        int value, key;
        scanf("%d %d", &value, &key);
        node[key].push_back(value);
        arr_m[i] = key;
    }
    bool all_access[n+1];
    memset(all_access, false, sizeof(all_access));
    int line = 0;
    std::vector<int> result;
    for(int i = 0; i < m; i++){
        if(all_access[arr_m[i]]) continue;
        all_access[arr_m[i]] = true;
        bool is_access[n+1];
        memset(is_access, false, sizeof(is_access));
        int count = 1;
        is_access[arr_m[i]] = true;
        SearchNode(is_access, arr_m[i], count);
        if(count == line) result.push_back(arr_m[i]);
        else if(count > line){
            result.clear();
            line = count;
            result.push_back(arr_m[i]);
        }
        //std::cout << "node : " << arr_m[i] << " , count : " << count << std::endl;
    }
    std::sort(result.begin(), result.end());
    for(auto i : result) std::cout << i << " ";
    return 0;
}


/** SCC 활용
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[10001];
vector<int> graph2[10001];
int arr[10001];
bool visited[10001];
bool visited2[10001];
bool done[10001];

int N, M;
int DFS(int to) {
	int com = 1, num;
	visited[to] = true;
	done[to] = true;
	for (int i = 0; i < graph[to].size(); i++) {
		num = graph[to][i];
		if (!visited[num])
			com += DFS(num);
	}
	return com;
}
void reverseDFS(int to, int val) {
	int com = 1, num;
	visited2[to] = true, arr[to] = val;
	for (int i = 0; i < graph2[to].size(); i++) {
		num = graph2[to][i];
		if (visited[num] && !visited2[num])
			reverseDFS(num, val);
	}
}
void reset() {
	for (int i = 1; i <= N; i++)
		visited[i] = false;
}
int main() {
	scanf("%d %d", &N, &M);
	int from, to, max_com = 0;
	while(M--) {
		scanf("%d %d", &from, &to);
		graph[to].push_back(from);
		graph2[from].push_back(to);
	}

	for (int i = 1; i <= N; i++) {
		if (!done[i]) {
			reset();
			arr[i] = DFS(i);
			reverseDFS(i, arr[i]);
			max_com = max(max_com, arr[i]);
		}
	}
	for (int i = 1; i <= N; i++)
		if (arr[i] == max_com)
			printf("%d ", i);
	return 0;
}
**/

#endif //MAIN_CPP_1325_H
