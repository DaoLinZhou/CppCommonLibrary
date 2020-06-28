//
// Created by Daolin on 2020/6/27.
//

#ifndef ALGORITHM_AVL_H
#define ALGORITHM_AVL_H
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

template <typename Key, typename Value>
class AVL{
private:
    struct Node{
        Key key;
        Value value;
        Node* left;
        Node* right;
        int height;

        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            left = NULL;
            right = NULL;
            height = 1;
        }

        Node(Node* node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
            height = node->height;
        }
    };

    Node* root;
    int count;

public:
    AVL() {
        root = NULL;
        count = 0;
    }

    ~AVL(){
        destroy(root);
    }

    int getSize(){ return count; }

    bool isEmpty(){
        return count == 0;
    }

    void insert(Key key, Value value){
        root = insert(root, key, value);
    }

    bool contain(Key key){
        return contain(root, key);
    }

    Value* search(Key key){
        Node* node = search(root, key);
        if(node == NULL)
            return NULL;
        return &(node->value);
    }

    Key minimum(){
        assert(count != 0);
        Node* minNode = minimum(root);
        return minNode->key;
    }

    Key maximum(){
        assert(count != 0);
        Node* maxNode = maximum(root);
        return maxNode->key;
    }

    void remove(Key key){
        root = remove(root, key);
    }

    // 判断该二叉树是否是一颗二分搜索树
    bool isBST(){
        vector<Key> keys;
        inOrder(root, keys);
        for(int i = 1; i < keys.size(); i++)
            if(keys[i-1] > keys[i])
                return false;
        return true;
    }

    bool isBalanced(){
        return isBalanced(root);
    }

private:

    Node* insert(Node* node, Key key, Value value){
        if(node == NULL) {
            count++;
            return new Node(key, value);
        }
        if(node->key == key)
            node->value = value;
        else if(node->key < key)
            node->right = insert(node->right, key, value);
        else
            node->left = insert(node->left, key, value);

        // 更新 height
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // 计算平衡因子
        int balanceFactor = getBalanceFactor(node);

        // 平衡维护
        // LL
        if(balanceFactor > 1 && getBalanceFactor(node->left) >= 0) {
            // 左子树和右子树高度差超过1, 并且是左边要高的, 并且不平衡的原因是因为左侧的左侧多添加了一个元素
            return rightRotate(node);
        }

        // RR
        if(balanceFactor < -1 && getBalanceFactor(node->right) <= 0){
            return leftRotate(node);
        }

        // LR
        if(balanceFactor > 1 && getBalanceFactor(node->left) < 0){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL
        if(balanceFactor < -1 && getBalanceFactor(node->right) > 0){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // 查找以node为根的二叉搜索树中是否包含键值为key的节点
    bool contain(Node* node, Key key) {
        if(node == NULL)
            return false;
        if(key == node->key)
            return true;
        else if(key < node->key)
            return contain(node->left, key);
        else
            return contain(node->right,key);
    }

    // 在以node为根的二叉搜索树中查找key所对应的value
    Node* search(Node* node, Key key) {
        if(node == NULL)
            return NULL;
        if(node->key == key)
            return node;
        else if(node->key > key)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    // 与后序遍历基本一致
    void destroy(Node* node) {
        if(node == NULL)
            return;
        destroy(node->left);
        destroy(node->right);
        delete node;
        count --;
    }

    Node* minimum(Node* node){
        if(node->left == NULL)
            return node;
        return minimum(node->left);
    }

    Node* maximum(Node* node){
        if(node->right == NULL)
            return node;
        return maximum(node->right);
    }

    Node* remove(Node* node, Key key){
        if(node == NULL)
            return NULL;

        Node* retNode;
        if(key > node->key){
            node->right = remove(node->right, key);
            retNode = node;
        }
        else if(key < node->key){
            node->left = remove(node->left, key);
            retNode = node;
        }
        else {
            if (node->left == NULL) {
                Node *rightNode = node->right;
                delete node;
                count--;
                retNode = rightNode;
            } else if (node->right == NULL) {
                Node *leftNode = node->left;
                delete node;
                count--;
                retNode = leftNode;
            } else {
                Node *successor = new Node(minimum(node->right));
                successor->right = remove(node->right, successor->key);
                successor->left = node->left;

                delete node;
                retNode = successor;
            }
        }

        // 删除后新的子树可能为空
        if(retNode == nullptr)
            return nullptr;

        // 更新height
        retNode->height = 1 + max(getHeight(retNode->left), getHeight(retNode->right));
        int balanceFactor = getBalanceFactor(retNode);

        // 平衡维护
        // LL
        if(balanceFactor > 1 && getBalanceFactor(retNode->left) >= 0) {
            // 左子树和右子树高度差超过1, 并且是左边要高的, 并且不平衡的原因是因为左侧的左侧多添加了一个元素
            return rightRotate(retNode);
        }

        // RR
        if(balanceFactor < -1 && getBalanceFactor(retNode->right) <= 0){
            return leftRotate(retNode);
        }

        // LR
        if(balanceFactor > 1 && getBalanceFactor(retNode->left) < 0){
            retNode->left = leftRotate(retNode->left);
            return rightRotate(retNode);
        }

        // RL
        if(balanceFactor < -1 && getBalanceFactor(retNode->right) > 0){
            retNode->right = rightRotate(retNode->right);
            return leftRotate(retNode);
        }

        return retNode;
    }

    int getHeight(Node* node){
        if(node == nullptr)
            return 0;
        return node->height;
    }

    // 获得节点node的平衡引子
    int getBalanceFactor(Node* node){
        if(node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    void inOrder(Node* node, vector<Key>& keys){
        if(node == nullptr)
            return;
        inOrder(node->left, keys);
        keys.push_back(node->key);
        inOrder(node->right, keys);
    }

    bool isBalanced(Node* node){
        if(node == nullptr)
            return true;
        if(abs(getBalanceFactor(node)) > 1)
            return false;
        return isBalanced(node->left) && isBalanced(node->right);
    }


    // 对节点y进行向右旋转操作，返回旋转后新的根节点x
    //        y                              x
    //       / \                           /   \
    //      x   T4     向右旋转 (y)        z     y
    //     / \       - - - - - - - ->    / \   / \
    //    z   T3                       T1  T2 T3 T4
    //   / \
    // T1   T2
    Node* rightRotate(Node* y){
        Node* x = y->left;
        Node* t3 = x->right;
        x->right = y;
        y->left = t3;

        // 更新height
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    // 对节点y进行向左旋转操作，返回旋转后新的根节点x
    //    y                             x
    //  /  \                          /   \
    // T1   x      向左旋转 (y)       y     z
    //     / \   - - - - - - - ->   / \   / \
    //   T2  z                     T1 T2 T3 T4
    //      / \
    //     T3 T4
    Node* leftRotate(Node* y){
        Node* x = y->right;
        Node* t2 = x->left;

        x->left = y;
        y->right = t2;

        // 更新height
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

};

#endif //ALGORITHM_AVL_H
