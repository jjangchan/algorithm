//
// Created by jjangchan on 2021-08-25.
// 1786 - 찾기(KMP)
//

#ifndef ALGORITHM_1786_H
#define ALGORITHM_1786_H

vector<int> getPi(string p)
{
    int m = (int)p.size(), j=0;
    vector<int> pi(m, 0);
    for(int i = 1; i< m ; i++)
    {
        while(j > 0 && p[i] != p[j])
            j = pi[j-1];
        if(p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}



vector<int>kmp(string s, string p){
    vector<int> ans;
    auto pi = getPi(p);
    int n = (int)s.size(), m = (int)p.size(), j =0;
    for(int i = 0 ; i < n ; i++)
    {
        while(j>0 && s[i] != p[j]) j = pi[j-1];
        if(s[i] == p[j])
        {
            if(j==m-1)
            {
                ans.push_back(i-m+1);
                j = pi[j];
            }
            else
            {
                j++;
            }
        }
    }
    return ans;
}

void Input()
{
    string s, p;
    getline(cin, s);
    getline(cin, p);
    auto matched = kmp(s,p);
    printf("%d\n", (int)matched.size());
    for(auto i : matched)
        printf("%d ", i+1);
}

#endif //ALGORITHM_1786_H
