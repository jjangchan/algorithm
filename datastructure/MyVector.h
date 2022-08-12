//
// Created by jjangchan on 2022/08/03.
//

#ifndef MAIN_CPP_MYVECTOR_H
#define MAIN_CPP_MYVECTOR_H

#include <string>

template <typename T>
class Vector {
    T* data = nullptr;
    int capacity = 0;
    int length = 0;

public:
    // 생성자
    Vector(int n = 1) : data((T*)malloc(sizeof(T)*n)), capacity(n), length(0) {}

    // 복사 생성자
    Vector(Vector<T>& v){
        data = (T*) malloc(sizeof(T)*v.length);
        for(int i = 0; i < v.length; i++){
            data[i] = v.data[i];
        }
        length = v.length;
    }

    Vector<T>& operator=(const Vector<T>& v){
        length = v.length;
        if(v.length > capacity){
            capacity = (capacity*2 > v.length+length) ? capacity*2 : v.length+length;
            free(data);
            data = (T*) malloc(sizeof(T)*v.length);
        }
        for(int i = 0; i < length; i++){
            data[i] = v.data[i];
        }
        return *this;
    }

    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(T s) {
        if (capacity <= length) {
            T* temp = (T*)malloc(sizeof(T)*2);
            for (int i = 0; i < length; i++) {
                temp[i] = data[i];
            }
            free(data);
            data = temp;
            capacity *= 2;
        }

        data[length] = s;
        length++;
    }

    // 임의의 위치의 원소에 접근한다.
    T operator[](int i) { return data[i]; }

    // x 번째 위치한 원소를 제거한다.
    void remove(int x) {
        for (int i = x + 1; i < length; i++) {
            data[i - 1] = data[i];
        }
        length--;
    }

    // 현재 벡터의 크기를 구한다.
    int size() { return length; }

    ~Vector() {
        if (data) {
            free(data);
        }
    }
};

template <>
class Vector<int> {
    int* data = nullptr;
    int capacity = 0;
    int length = 0;

public:
    // 생성자
    Vector(int n = 1) : data(new int[n]), capacity(n), length(0) {}

    // 복사 생성자
    Vector(const Vector<int>& v){
        length = v.length;
        data = new int[length];
        for(int i = 0; i < length; i++){
            data[i] = v.data[i];
        }
    }

    Vector<int>& operator=(const Vector<int>& v){
        length = v.length;
        if(v.length > capacity){
            capacity = (capacity*2 > v.length+length) ? capacity*2 : v.length+length;
            delete[] data;
            data = new int[length];
        }

        for(int i = 0; i < length; i++){
            data[i] = v.data[i];
        }
        return *this;
    }



    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(int s) {
        if (capacity <= length) {
            int* temp = new int[capacity * 2];
            for (int i = 0; i < length; i++) {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity *= 2;
        }

        data[length] = s;
        length++;
    }

    // 임의의 위치의 원소에 접근한다.
    int operator[](int i) { return data[i]; }

    // x 번째 위치한 원소를 제거한다.
    void remove(int x) {
        for (int i = x + 1; i < length; i++) {
            data[i - 1] = data[i];
        }
        length--;
    }

    // 현재 벡터의 크기를 구한다.
    int size() { return length; }

    ~Vector() {
        if (data) {
            delete[] data;
        }
    }
};

template <>
class Vector<double> {
    double* data = nullptr;
    int capacity = 0;
    int length = 0;

public:
    // 생성자
    Vector(int n = 1) : data(new double[n]), capacity(n), length(0) {}

    // 복사 생성자
    Vector(const Vector<double>& v){
        data = new double[v.length];
        for(int i = 0; i < v.length; i++){
            data[i] = v.data[i];
        }
        length = v.length;
    }

    Vector<double>& operator=(const Vector<double>& v){
        length = v.length;
        if(v.length > capacity){
            capacity = (capacity*2 > v.length+length) ? capacity*2 : v.length+length;
            delete[] data;
            data = new double[length];
        }

        for(int i = 0; i < length; i++){
            data[i] = v.data[i];
        }
        return *this;
    }

    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(double s) {
        if (capacity <= length) {
            double* temp = new double[capacity * 2];
            for (int i = 0; i < length; i++) {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity *= 2;
        }

        data[length] = s;
        length++;
    }

    // 임의의 위치의 원소에 접근한다.
    double operator[](int i) { return data[i]; }

    // x 번째 위치한 원소를 제거한다.
    void remove(int x) {
        for (int i = x + 1; i < length; i++) {
            data[i - 1] = data[i];
        }
        length--;
    }

    // 현재 벡터의 크기를 구한다.
    int size() { return length; }

    ~Vector() {
        if (data) {
            delete[] data;
        }
    }
};

template <>
class Vector<std::string> {
    std::string* data = nullptr;
    int capacity = 0;
    int length = 0;

public:
    // 생성자
    Vector(int n = 1) : data(new std::string[n]), capacity(n), length(0) {}

    // 복사 생성자
    Vector(const Vector<std::string>& v){
        data = new std::string[v.length];
        for(int i = 0; i < v.length; i++){
            data[i] = v.data[i];
        }
        length = v.length;
    }

    Vector<std::string>& operator=(const Vector<std::string>& v){
        length = v.length;
        if(v.length > capacity){
            capacity = (capacity*2 > v.length+length) ? capacity*2 : v.length+length;
            delete[] data;
            data = new std::string[length];
        }

        for(int i = 0; i < length; i++){
            data[i] = v.data[i];
        }
        return *this;
    }

    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(std::string s) {
        if (capacity <= length) {
            std::string* temp = new std::string [capacity * 2];
            for (int i = 0; i < length; i++) {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity *= 2;
        }

        data[length] = s;
        length++;
    }

    // 임의의 위치의 원소에 접근한다.
    std::string operator[](int i) { return data[i]; }

    // x 번째 위치한 원소를 제거한다.
    void remove(int x) {
        for (int i = x + 1; i < length; i++) {
            data[i - 1] = data[i];
        }
        length--;
    }

    // 현재 벡터의 크기를 구한다.
    int size() { return length; }

    ~Vector() {
        if (data) {
            delete[] data;
        }
    }
};
#endif //MAIN_CPP_MYVECTOR_H
