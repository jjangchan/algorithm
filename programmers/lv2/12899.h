//
// Created by JKC on 18/05/2020.
// 12899 - 124나라의 숫자
//

#ifndef ALGORITHM_12899_H
#define ALGORITHM_12899_H
#include <string>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool run_up(int up_sum, string *answer , char a)
{
    switch(a)
    {
        case '1':
            answer->replace(up_sum,1,"2");
            break;
        case '2':
            answer->replace(up_sum,1,"4");
            break;
        case '4':
            answer->replace(up_sum,1,"1");
            return true;
    }
    return  false;
}

string solution(int n) {
    string answer = "";

    int digit = 1 ;
    int sum =-1;
    bool s_q = false;

    for(int i=0; i<20;i++)
    {
        sum +=pow(3,i);
        if(sum<n && sum+pow(3,i+1) >=n)
        {
            digit = i+1;
            break;
        }
    }

    int end = n - sum;

    int cnt = 0;

    for(int i=digit; i>=1;i--)
    {
        if(pow(3,i) >end)
        {
            answer +="1";
        }
        else{
            answer +="4";
            cnt += 1;
        }
    }

    int start = pow(3,cnt);

    for(int i=start; i<end; i++)
    {
        int up_sum = answer.size()-1;
        while(run_up(up_sum, &answer , answer[up_sum]))
        {
            if(up_sum <0){
               break;
            }else{
                up_sum -=1;
            }
        }
    }
    cout << answer;
    return answer;
}

/**
 * using namespace std;

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
 *
 */
#endif //ALGORITHM_12899_H
