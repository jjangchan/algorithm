//
// Created by JKC on 15/05/2020.
// 42587 - 프린터
//

#ifndef ALGORITHM_42587_H
#define ALGORITHM_42587_H
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int solution() {
    vector<int> priorities{2,1,3,2};

    int answer = 0;
    map<int,int> m;
    queue<int> q;
    int cnt = 1;

    int v_length = priorities.size();

    //queue initialize
    for(int i=0; i<v_length;i++)
    {
        q.push(i);
    }

    while(!q.empty())
    {
        bool flag = false;
        int index_one = priorities[0];
        int q_num = q.front();
        for(int i =1; i<priorities.size(); i++)
        {
           if(index_one < priorities[i])
           {
               flag = true;
               break;
           }
        }
        if(flag)
        {
            q.push(q_num);
            q.pop();
            priorities.push_back(index_one);
            priorities.erase(priorities.begin());
        }else{
            m.insert(make_pair(q_num,cnt));
            priorities.erase(priorities.begin());
            q.pop();
            cnt++;
        }
    }
    answer = m.find(2)->second;
    return answer;
}
#endif //ALGORITHM_42587_H
