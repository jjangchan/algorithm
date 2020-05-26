//
// Created by JKC on 18/05/2020.
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
#endif //ALGORITHM_12899_H
