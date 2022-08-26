//
// Created by jjangchan on 2022/08/26.
// 후보키
//

#ifndef MAIN_CPP_42890_H
#define MAIN_CPP_42890_H

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <unordered_map>
/** [good] -> 비트 연산자 사용
 *
 *  using namespace std;
bool possi(vector<int> &vec,int now){
    for(int i=0;i<vec.size();i++)
        if((vec[i]&now)==vec[i])return false;
    return true;
}
int solution(vector<vector<string>> relation) {
    int n=relation.size();
    int m=relation[0].size();
    vector<int> ans;
    for(int i=1;i<(1<<m);i++){
        set<string> s;
        for(int j=0;j<n;j++){
            string now="";
            for(int k=0;k<m;k++){
                if(i&(1<<k))now+=relation[j][k];
            }
            s.insert(now);
        }
        if(s.size()==n&&possi(ans,i))ans.push_back(i);
    }
    return ans.size();
}
 */

using namespace std;

std::unordered_map<std::string,int> m;

void com(const int start, const int max, const std::vector<std::vector<std::string>>& rel, const std::string& cols){
    if(cols.size() >= max){
        std::set<std::string> s;
        for(int i = 0; i < rel.size(); i++) {
            std::string str = "";
            for(int j = 0; j < cols.size(); j++){
                int col = cols[j]-'0';
                str.append(rel[i][col]+std::to_string(col));
            }
            s.insert(str);
        }
        if(s.size() == rel.size()) m[cols] = 0;
        return;
    }
    for(int i = start; i < rel[0].size(); i++){
        com(i+1, max, rel, cols+std::to_string(i));
    }
}

bool check(const int start, const int max, const std::string& p, const std::string& s){
    if(p.size() >= max) return true;
    if(m.find(p) != m.end()) return false;
    for(int i = start; i < s.size(); i++){
        if(!check(i+1, max, p+s[i], s)) return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    for(int i = 1; i <= relation[0].size(); i++)
        com(0, i, relation, "");
    for(const auto& pa : m){
        bool is = true;
        for(int i = 1; i <= pa.first.size(); i++){
           is = check(0, i, "", pa.first);
           if(!is) break;
        }
        if(is) answer++;
    }
    return answer;
}

#endif //MAIN_CPP_42890_H
