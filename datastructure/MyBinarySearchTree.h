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

    void set_data(T d) { data = d;}
    T get_data() const {return data;}

    void set_left(Node* l){ left = l;}
    Node* get_left() const {return left;}

    void set_right(Node* r){ right = r;}
    Node* get_right() const {return right;}

    bool empty_leaf(){ return left == nullptr && right == nullptr;}
    Node* search_node(T key){
        if(data == key) return this;
        else if(data > key && left != nullptr) return left->SearchNode(key); // 왼쪽 탐색
        else if(data < key && right != nullptr) return right->SearchNode(key); // 오른쪽 탐색
        return nullptr;
    }
};

template<typename T>
class BinaryTree{
private:
    Node<T>* root;
public:

    // constructor
    BinaryTree(){
        root = nullptr;
    }

    // copy constructor
    BinaryTree(const BinaryTree<T>& bt){}

    BinaryTree<T>& operator=(const BinaryTree<T>& bt){return (*this);}

    // destructor
    ~BinaryTree(){}

public:
    void preorder(){
        std::cout << "Pre-order Traversal [ ";
        Traversal(1, root);
        std::cout <<"]" << std::endl;
    }

    void inorder(){
        std::cout << "In-order Traversal [ ";
        Traversal(2, root);
        std::cout <<"]" << std::endl;

    }

    void postorder(){
        std::cout << "Post-order Traversal [ ";
        Traversal(3, root);
        std::cout <<"]" << std::endl;
    }


    int size(){
        return (is_empty()) ? 0 : size(root);
    }

    int length_leaf(){return (is_empty()) ? 0 : length_leaf(root);}

    int height(){return (is_empty()) ? 0 : height(root);}

    bool is_empty(){return (root == nullptr) ? 1 : 0;}

    Node<T>* get_root(){return root;};

    void set_root(Node<T>* node){root = node;}

private:
    int height(Node<T>* node){
        if(node == nullptr) return 0;
        int left_height = height(node->get_left());
        int right_height = height(node->get_right());
        return (left_height > right_height) ? left_height + 1 : right_height+1;
    }

    int length_leaf(Node<T>* node){
        if(node == nullptr) return 0;
        if(node->empty_leaf()) return 1;
        else return length_leaf(node->get_left()) + length_leaf(node->get_right());
    }

    int size(const Node<T>* node){
        if(node == nullptr) return 0;
        return 1 + size(node->get_left()) + size(node->get_right());
    }

    void Traversal(const int order, Node<T>* node){
        if(node != nullptr){
            if(order == 1) std::cout << node->get_data()<< " ";
            Traversal(order, node->get_left());
            if(order == 2) std::cout << node->get_data()<< " ";
            Traversal(order, node->get_right());
            if(order == 3) std::cout << node->get_data()<< " ";
        }
    }

};

template<typename T>
class BinarySearchTree : public BinaryTree<T>{
public:
    BinarySearchTree() : BinaryTree<T>(){
    }
    virtual ~BinarySearchTree(){
        std::cout << std::endl;
        std::cout << "=============================== delete =============================== "<< std::endl;
        destroy(this->get_root());
        this->set_root(nullptr);
        std::cout << "======================================================================= " << std::endl;
    }

public:
    Node<T>* search(const T& data){return search_iter(this->get_root(), data);}

    void insert(const T data){
        if(this->get_root() == nullptr){
            Node<T>* node = new Node<T>(data, nullptr, nullptr);
            this->set_root(node);
        }else{
            insert_inter(this->get_root(), data);
        }
    }

    void remove(const T& data){
        if(this->is_empty()) return;
        Node<T>* parent = nullptr;
        Node<T>* delete_node = this->get_root();
        while(delete_node != nullptr && delete_node->get_data() != data){
            parent = delete_node;
            delete_node = (delete_node->get_data() > data) ? delete_node->get_left() : delete_node->get_right();
        }
        if(delete_node == nullptr){
            std::cout << "not contain key" << std::endl;
            return;
        }
        remove(parent, delete_node);
    }

private:
    Node<T>* search_iter(Node<T>* node, const T& data){
        while(node != nullptr){
            if(node->get_data() == data) return node;
            else if(node->get_data() > data) node = node->get_left();
            else if(node->get_data() < data) node = node->get_right();
        }
        return nullptr;
    }

    void insert_inter(Node<T>* node, const T data){
        while(true){
            if(node->get_data() == data) return;
            else if(node->get_data() > data){
                if(node->get_left() == nullptr){
                    Node<T> *temp = new Node<T>(data, nullptr, nullptr);
                    node->set_left(temp);
                    return;
                }
                node = node->get_left();
            }else if(node->get_data() < data){
                if(node->get_right() == nullptr){
                    Node<T> *temp = new Node<T>(data, nullptr, nullptr);
                    node->set_right(temp);
                    return;
                }
                node = node->get_right();
            }
        }
    }

    void destroy(Node<T>* node){
        if(node == nullptr) return;
        destroy(node->get_right());
        destroy(node->get_left());
        std::cout << "delete node : " << node << std::endl;
        std::cout << "delete data : " << node->get_data() << std::endl;
        node->set_right(nullptr);
        node->set_left(nullptr);
        delete node;
        node = nullptr;
    }

    void remove(Node<T>* parent, Node<T>* delete_node){
        if(delete_node->empty_leaf()){
            // case 1) leaf node
            if(delete_node == this->get_root()){
                this->set_root(nullptr);
            }else{
                (parent->get_right() == delete_node) ? parent->set_right(nullptr) : parent->set_left(nullptr);
            }
        }else if(delete_node->get_right() == nullptr || delete_node->get_left() == nullptr){
            // case 2) child node 1
            Node<T>* child_node = (delete_node->get_right() != nullptr) ? delete_node->get_right() : delete_node->get_left();
            if(delete_node == this->get_root()){
                this->set_root(child_node);
            }else{
                (parent->get_right() == delete_node) ? parent->set_right(child_node) : parent->set_left(child_node);
            }

        }else{
            // case 3) child node 2
            Node<T>* temp = delete_node;
            Node<T>* temp_child = delete_node->get_right();
            while(temp_child->get_left() != nullptr){
                temp = temp_child;
                temp_child = temp_child->get_left();
            }

            if(temp->get_left() == temp_child){
                temp->set_left(temp_child->get_right());
            }else{
                temp->set_right(temp_child->get_right());
            }

            //swap
            delete_node->set_data(temp_child->get_data());
            delete_node = temp_child;

        }

        delete delete_node;
        delete_node = nullptr;
    }



};

#endif //MAIN_CPP_MYBINARYSEARCHTREE_H
