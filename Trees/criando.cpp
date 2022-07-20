#include <iostream>

struct bnode{
    int value;
    bnode * left;
    bnode * right;
    bnode(int value = 0, bnode * left = nullptr, bnode * right = nullptr){
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

class btree{

public:
    bnode * root;
    btree(){
        root = nullptr;
    }

    ~btree(){
        clear(root);
    }

    btree(btree * other){
        clone(other -> root);
    }

    bnode * clone (bnode * other){
        if(other == nullptr){
            return nullptr;
        }
        bnode * node = new bnode(other -> value);
        node -> left = clone(other -> left);
        node -> right = clone(other -> right);
        return node;
    }

    bool equals (bnode * node, bnode * other){
        if(node == nullptr && other == nullptr)
            return true;
        if(node == nullptr && other != nullptr)
            return false;
        if(node != nullptr && other == nullptr)
            return false;
        if(node->value != other->value)
            return false;
        return equals(node -> left, other ->left) && equals (node -> right, other -> right);
    }

    bool find(bnode * node, int value){
        if(node == nullptr)
            return false;
        if(node -> value == value)
            return true;
        return find (node ->left, value) | find(node ->right, value);
    }

    int min(bnode * node){
        int minimo = node -> value;
        if(node -> left != nullptr)
            minimo = std::min(minimo,min(node->left));
        if(node -> right != nullptr)
            minimo = std::min(minimo,min(node->left));
        return minimo;
    }

    int qtd (bnode * node){
        if(node == nullptr)
            return 0;
        return 1+ qtd (node->left) + qtd(node-> right);
    }

    void clear (bnode * node){
        if(node == nullptr)
            return;
        clear (node-> left);
        clear (node->right);
        delete node;
    }

    void gambifill(){
        root = new bnode(5);
        root->left = new bnode(9);
        root->left->left = new bnode(4);
        root->left->right = new bnode(6);
        root->right = new bnode(8);
        root->right->right = new bnode(7);
    }

    void show (bnode * node){
        if(node == nullptr)
            return;
        std::cout << node -> value << " ";
        show(node -> left);
        show(node -> right);
    }
};