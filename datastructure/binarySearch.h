//
// Created by jjangchan on 2021-08-17.
//

#ifndef EX2_NEW_DELETE_H_BINARYSEARCH_H
#define EX2_NEW_DELETE_H_BINARYSEARCH_H

#include <iostream>
#include <vector>
#include <algorithm>


template <typename T>
int BinarySearch(const std::vector<T> v,const int left, const int right, const T value)
{
    if(right < left)
        return -1;
    int mid = (left+right)/2;
    if(v[mid] == value)
        return mid;
    else if(v[mid] > value)
        return BinarySearch(v, left, mid-1, value);
    else
        return BinarySearch(v, mid+1, right, value);
}

#endif //EX2_NEW_DELETE_H_BINARYSEARCH_H
