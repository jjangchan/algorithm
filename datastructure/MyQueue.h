//
// Created by jjangchan on 2022/04/15.
//

#ifndef MAIN_CPP_MYQUEUE_H
#define MAIN_CPP_MYQUEUE_H

#include <iostream>

template <typename T>
class MyQueue{
private:
   struct Node{
       T data;
       Node* front_node;
       Node(T d):data(d), front_node(nullptr){}
   };
   //Node* current_node;
   Node* front_node;
   Node* pear_node;
   int size;
public:
    MyQueue():front_node(new Node(0)), size(0){
        pear_node = front_node;
    }
    ~MyQueue(){
        //std::cout << "node1 : " << front_node << std::endl;
        //std::cout << "node2 : " << front_node->front_node << std::endl;
        while(front_node != pear_node){
            Node* current_node = front_node;
            front_node = front_node->front_node;
            delete current_node;
            std::cout << "delete.." << std::endl;
            current_node = nullptr;
        }
        if(pear_node != nullptr){
            std::cout << "last delete.." << std::endl;
            delete pear_node;
            pear_node = nullptr;
        }
    }

    void push(T d){
        Node* temp = new Node(d);
        pear_node->front_node = temp;
        pear_node = temp;
        size++;
    }

    int length () const {return size;}

    T remove(){
        if(pear_node == front_node){
            throw std::runtime_error("empty Queue");
        }
        T d = front_node->front_node->data;
        Node* temp = front_node->front_node;
        if(front_node != nullptr){
            delete front_node;
            front_node = nullptr;
        }
        front_node = temp;
        size--;
        return d;
    }

    bool is_empty() const {return pear_node == front_node;}
private:
};

#endif //MAIN_CPP_MYQUEUE_H
