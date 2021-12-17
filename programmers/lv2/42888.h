//
// Created by jjangchan on 2021-12-17.
// 오픈채팅방
//

#ifndef MAIN_CPP_42888_H
#define MAIN_CPP_42888_H

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <functional>

using namespace std;

class OpenChat{
private:
    std::string user_id;
    std::string nick_name;
public:
    OpenChat(std::string _user_id, std::string _nick_name):user_id(_user_id), nick_name(_nick_name){}
    OpenChat(const OpenChat* chat): user_id(chat->user_id), nick_name(chat->nick_name){}
    virtual ~OpenChat(){}
    virtual std::string Enter() = 0;
    virtual std::string Leave() = 0;
    void SetName(const std::string name){ this->nick_name = name;}

protected:
    std::string GetId() const {return user_id;}
    std::string GetName() const {return  nick_name;}
};

class Account : public OpenChat{
public:
    Account(std::string user_id, std::string nick_name): OpenChat(user_id, nick_name){}
    ~Account(){}
    std::string Enter() override{return GetName()+"님이 들어왔습니다.";}
    std::string Leave() override{return GetName()+"님이 나갔습니다.";}
};

std::unordered_map<std::string, OpenChat*> map_id;
std::vector<std::function<std::string() >> status;


void Operate(std::string* keys){
    if(keys[0] == "Enter"){
        // find log
        if(map_id.count(keys[1])){
            map_id[keys[1]]->SetName(keys[2]);
            // non-static member function must be called with an object
            // https://stackoverflow.com/questions/7582546/using-generic-stdfunction-objects-with-member-functions-in-one-class?answertab=votes#tab-top
            status.push_back(std::bind(&OpenChat::Enter, map_id[keys[1]]));
        }else{
            OpenChat *account = new Account(keys[1], keys[2]);
            map_id[keys[1]] = account;
            status.push_back(std::bind(&OpenChat::Enter, account));
        }
    }else if(keys[0] == "Leave") status.push_back(std::bind(&OpenChat::Leave, map_id[keys[1]]));
    else map_id[keys[1]]->SetName(keys[2]);
}

vector<string> solution(vector<string> record) {
    std::string key[3];
    for(std::string& s : record){
        istringstream iss(s);
        iss >> key[0] >> key[1] >> key[2];
        Operate(key);
    }
    vector<string> answer;
    for(auto& fun : status) answer.push_back(fun());
    return answer;
}

#endif //MAIN_CPP_42888_H
