//
// Created by JKC on 08/06/2020.
// 1829 - 카카오프렌즈 컬러링 북
//

#ifndef ALGORITHM_1829_H
#define ALGORITHM_1829_H

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int sum;

void DFS(int node,bool chk[],vector<int> graph[])
{
    chk[node] = true;
    sum++;
    for(int i=0; i<graph[node].size();i++)
    {
        if(!chk[graph[node][i]])
        {
            DFS(graph[node][i],chk,graph);
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    const int length = m*n;

    vector<int> graph[10000];
    bool chk[10000]={false};

    queue<int> nodes;
    vector<int> result;

    //node initialization
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int counter = (i * n) + j;
            if(picture[i][j]!=0){
                nodes.push(counter);

                //좌 노드 확인
                if (j!=0 && picture[i][j] == picture[i][j-1]) {
                    graph[counter - 1].push_back(counter);
                    graph[counter].push_back(counter-1);
                }
                //상 노드 확인
                if (i!=0 && picture[i-1][j] == picture[i][j]) {
                    graph[counter - n].push_back(counter);
                    graph[counter].push_back(counter-n);
                }
            }
        }
    }


    while(!nodes.empty())
    {
        int node = nodes.front();
        sum = 0;
        if(!chk[node])
        {
            DFS(node,chk,graph);
            result.push_back(sum);
        }
        nodes.pop();
    }
    int max = *max_element(result.begin(), result.end());

    number_of_area = result.size();
    max_size_of_one_area = max;

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

#endif //ALGORITHM_1829_H
