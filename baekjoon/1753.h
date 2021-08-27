//
// Created by jjangchan on 2021-04-12.
// BAEKJOON - 1753 최단경로
//

#ifndef ALGORITHM_1753_H
#define ALGORITHM_1753_H

#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

vector<pair<int, int>> *graph;
map<int, int> d;
map<int, int> t;
int V,E;
int start;


namespace BAEKJOON1752
{
    void Output()
    {
        map<int, int>::iterator iter;
        for(int i=1; i<V+1; i++) {
            iter = d.find(i);
            if(iter != d.end())
            {
                cout << iter->second << endl;
            }
            else
            {
                cout << "INT" << endl;
            }
        }
    }

    void Start()
    {
        d.insert(pair<int,int>(start, 0));
        t.insert(pair<int, int>(start, 0));
        int index = start;
        int count = 1;
        bool is_node[V+1];

        while(count != V)
        {
            int row_size = graph[index].size();
            for(int i=0; i<row_size; i++)
            {


            }
            count += 1;
        }
    }

    void Input()
    {
        cin >> V >> E;
        cin >> start;
        graph = new vector<pair<int, int>>[V+1];
        int u, v, w;
        for (int e = 0; e < V+1; e++) {
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(w, v));
        }
        Start();
        Output();
    }
}
#endif //ALGORITHM_1753_H
