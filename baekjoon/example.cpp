//
// Created by jjangchan on 2021-04-22.
//

#include "example.h"

PrivateAccessError::PrivateAccessError() {

    a = 1;   // (1)

    b = 1;   // (2)

}

PrivateAccessError::PrivateAccessError(int x) {

    a = x;   // (3)

    b = x;   // (4)

}

void PrivateAccessError::f() {

    a = 5;   // (5)

    b = 5;   // (6)

}

void PrivateAccessError::g() {

    a = 6;   // (7)

    b = 6;   // (8)
}