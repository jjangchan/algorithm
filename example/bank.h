//
// Created by jjangchan on 2023/04/22.
//

#ifndef MAIN_CPP_BANK_H
#define MAIN_CPP_BANK_H

class Bank{
private:
    // resource counter
    int m;
    // process counter
    int n;
    int **available;
    int *max;
    int *allocation;

public:
    Bank(const int _m, const int _n):m(_m), n(_n){
        max = new int[m];
        //for(int i = 0; i < )
    }
    ~Bank(){}
private:

}

#endif //MAIN_CPP_BANK_H
