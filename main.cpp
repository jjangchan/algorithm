#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

bool possi(vector<int> &vec,int now){
    for(int i=0;i<vec.size();i++)
        if((vec[i]&now)==vec[i])return false;
    return true;
}

int solution(vector<vector<string>> relation) {
    int n=relation.size(), m=relation[0].size();
    vector<int> ans;
    for(int i = 1; i < (1 << m); i++){
        for(int j = 0; j < n; j++){
            std::string now;
            for(int k = 0; k < m; k++){
                if(i&(1<<k)) now.append(relation[j][k]);
            }
            std::cout << now << std::endl;
        }
    }
    return ans.size();
}


int main(){
    return solution({{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}});
}

