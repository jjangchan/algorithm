#include <iostream>
#include <string>
#include <cmath>

std::string rabin_karp(const std::string& str, const std::string& pattern){
    int patter_length = pattern.length();
    int str_hash = 0, pattern_hash = 0;
    for(int i = 0; i < patter_length; i++){
        str_hash += (str[i]* pow(2, patter_length-1-i);
        pattern_hash += (pattern[i]* pow(2, patter_length-1-i);
    }
    int first = str[0]* pow(2, patter_length-1);

}

int main() {
    std::string str = "avsdasds2ddsavvbsda";
    std::string patter = "ddsavvb";
    std::string test = "aaaaa";
    rabin_karp(str, patter);
    return 0;
}