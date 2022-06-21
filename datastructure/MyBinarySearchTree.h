//
// Created by jjangchan on 2022/05/07.
//

#ifndef MAIN_CPP_MYBINARYSEARCHTREE_H
#define MAIN_CPP_MYBINARYSEARCHTREE_H

#include <iostream>

template <typename T>
struct Node{
private:
    T data;
    Node* left;
    Node* right;
public:
    Node(T _d, Node* _l, Node*  _r):data(_d), left(_l), right(_r){}
    ~Node(){}

    void SetData(T d) { data = d;}
    T GetData() const {return data;}

    void SetLeft(Node* l){ left = l;}
    Node* GetLeft() const {return left;}

    void SetRight(Node* r){ right = r;}
    Node* GetRight() const {return right;}

    bool EmptyLeaf(){ return left == nullptr && right == nullptr;}
    Node* SearchNode(T key){
        if(data == key) return this;
        else if(data > key && left != nullptr) return left->SearchNode(key); // 왼쪽 탐색
        else if(data < key && right != nullptr) return right->SearchNode(key); // 오른쪽 탐색
        return nullptr;
    }

    void preorder(){
        std::cout << "Pre-order Traversal [ ";
        Traversal(1, this);
        std::cout <<"]" << std::endl;
    }

    void inorder(){
        std::cout << "In-order Traversal [ ";
        Traversal(2, this);
        std::cout <<"]" << std::endl;

    }

    void postorder(){
        std::cout << "Post-order Traversal [ ";
        Traversal(3, this);
        std::cout <<"]" << std::endl;
    }

    void Traversal(const int order, Node* node){
        if(node != nullptr){
            if(order == 1) std::cout << node->data << " ";
            Traversal(order, node->left);
            if(order == 2) std::cout << node->data << " ";
            Traversal(order, node->right);
            if(order == 3) std::cout << node->data << " ";
        }
    }

};

#endif //MAIN_CPP_MYBINARYSEARCHTREE_H
