#include <iostream>
<<<<<<< HEAD
#include <string>
#include <cmath>
#include <vector>
#include <chrono>

int rabin_karp(const std::string& str, const std::string& pattern){
    int pattern_length = pattern.length();
    int str_hash = 0, pattern_hash = 0;
    for(int i = 0; i < pattern_length; i++){
        str_hash += (str[i]* (int)pow(2, pattern_length-1-i));
        pattern_hash += (pattern[i]* (int)pow(2, pattern_length-1-i));
    }
    // start , 시간복잡도 = O(n)
    for(int i = 0; i <= str.length()-pattern_length; i++){
        if(str_hash == pattern_hash){
            // verify
            bool is = true;
            for(int j = 0; j < pattern_length; j++){
                if(pattern[j] != str[i+j]){
                    is = false;
                    break;
                }
            }
            if(is) return i;
        }else if(i != str.length()-pattern_length){
            int first = str[i]* pow(2, pattern_length-1);
            str_hash = 2*(str_hash-first)+str[i+pattern_length];
        }
    }
    return -1;
}

std::vector<int> Test1(){
    std::vector<int> v;
    for(int i = 0; i < 100000000; i++) v.push_back(i);
    return v;
}

void Test1(std::vector<int>& v){
    for(int i = 0; i < 100000000; i++) v.push_back(i);
}
=======
#include <vector>

>>>>>>> cbc00725551a3e3cdb8f349d9df9f0c394524e7a


int main() {
<<<<<<< HEAD
    auto start = std::chrono::steady_clock::now();
    std::vector<int> v1 = Test1();
    auto end = std::chrono::steady_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout << elapsed_time << std::endl;

    start = std::chrono::steady_clock::now();
    std::vector<int> v2;
    Test1(v2);
    end = std::chrono::steady_clock::now();
    elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    std::cout << elapsed_time << std::endl;
=======
    int n = 3;
>>>>>>> cbc00725551a3e3cdb8f349d9df9f0c394524e7a
    return 0;
}