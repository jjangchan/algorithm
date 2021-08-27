//
// Created by jjangchan on 2021-04-22.
//

#ifndef ALGORITHM_EXAMPLE_H
#define ALGORITHM_EXAMPLE_H

using namespace std;

class PrivateAccessError {

private:

public:

    int a;
    int b;

    PrivateAccessError(int x);
    PrivateAccessError();
    void f();

    void g();

};

#endif //ALGORITHM_EXAMPLE_H
