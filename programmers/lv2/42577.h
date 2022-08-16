#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    std::sort(phone_book.begin(), phone_book.end(), [](const std::string& a, const std::string &b)->bool {
        return a.size() < b.size();
    });
    std::vector<int> lens;
    std::unordered_map<std::string,int> m;
    lens.push_back(phone_book[0].size());

    for(const auto& s : phone_book){
        if(lens[lens.size()-1] != s.size()) lens.push_back(s.size());
        for(int i = 0; i < lens.size() && lens[i] < s.size(); i++){
            if(m.find(s.substr(0,lens[i])) != m.end()) return false;
        }
        m[s]++;
    }
    return true;
}

/** best solution
bool solution(vector<string> phone_book) {
    std::sort(phone_book.begin(), phone_book.end()); // NlogN
    for(int i = 0; i < phone_book.size()-1; i++){ // N
        if(phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size())) return false;
    }
    return true;
}
**/
