//
// Created by JKC on 31/05/2020.
//

#ifndef ALGORITHM_12899_2_H
#define ALGORITHM_12899_2_H
#include <string>
#include <iostream>
#include <queue>

using namespace std;

string solution(int n) {
    string answer="";

    bool down = false;
    queue<int> q;

    while(n>0)
    {
        int a = n%3;
        q.push(a);
        n = n/3;
    }

    while(!q.empty())
    {
        int a = 0;
        if(!down){
            a = q.front();
        }else{
            a =q.front()-1;
        }
        if(a <= 0){
            down = true;
        }else{
            down = false;
        }
        answer.insert(0,to_string(a));
        q.pop();
    }
    if(answer[0] == '0')answer.erase(0,1);
    for(int i=0; i<answer.length();i++)
    {
        if(answer[i] == '-'){
            answer.replace(i,2,"2");
        }else if(answer[i] == '0'){
            answer[i] = '4';
        }
    }
    return answer;
}
#endif //ALGORITHM_12899_2_H
