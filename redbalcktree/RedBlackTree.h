#pragma once

#include <vector>
using std::vector;


template <typename Key, typename Value>
struct NodeT{
    Key key;
    Value value;
    NodeT* left;
    NodeT* right;
    NodeT* parent;
    bool isBlack;

    NodeT(Key key, Value value){
        this->key = key;
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
        this->isBlack = false;
    }

    NodeT(NodeT<Key, Value>* parent, NodeT<Key, Value>* node){
        this->key = node->key;
        this->value = node->value;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = parent;
        this->isBlack = node->isBlack;
    }

};

template <typename Key, typename Value>
class RedBlackTree{

private:
    typedef NodeT<Key, Value> Node;
    int count;
    Node* root;

public:

    RedBlackTree();
    RedBlackTree(RedBlackTree<Key, Value>& rbTree);
    RedBlackTree<Key, Value>& operator=(const RedBlackTree<Key, Value>& rbTree);
    ~RedBlackTree();

    bool insert(Key key, Value value);
    bool remove(Key key);
    bool search(Key key) const;
    vector<Value> search(Key key1, Key key2) const;
    vector<Value> values() const;
    vector<Key> keys() const;
    int size() const;
    NodeT<Key, Value>* getRoot();

    // test rbTree
    bool isRBTree(){
        bool isBlackBalance = true;
        bool redSeparate = true;
        getBlackHeight(root, isBlackBalance, redSeparate);
        return isBlackBalance && redSeparate;
    }

    // return the black height of the tree, and test black balance and red separate
    int getBlackHeight(Node* node, bool& isBalance, bool& redSeparate){
        if(node == nullptr) return 0;
        int leftH = getBlackHeight(node->left, isBalance, redSeparate);
        int rightH = getBlackHeight(node->right, isBalance, redSeparate);
        if(leftH != rightH)
            isBalance = false;
        if(isRed(node)){
            if(isRed(node->left) || isRed(node->right))
                redSeparate = false;
            return max(leftH, rightH);
        }
        return 1 + max(leftH, rightH);
    }

private:

    void destroy(Node* node);
    Node* find(Node* node, Key key) const;  // find the node with key

    Node* insert(Node* node, Node* h);  // BST insert
    void leftRotate(Node* node);
    void rightRotate(Node* node);
    bool isRed(Node* node);
    void pairs(vector<Key>& keys, vector<Value>& values) const;
    void inOrderTraversal(Node* node, vector<Key>& keys, vector<Value>& values) const;
    void copy(Node* node1, Node* node2);
    Node* maximum(Node* node);
    void fixup(Node* node);
    Node* sibling(Node* node);  // get node's sibling. node is not root, and it must has sibling

};


template<typename Key, typename Value>
RedBlackTree<Key, Value>::RedBlackTree() {
    root = nullptr;
    count = 0;
}


template<typename Key, typename Value>
RedBlackTree<Key, Value>::RedBlackTree(RedBlackTree<Key, Value> &rbTree) {
    root = nullptr;
    count = 0;
    if(rbTree.size() > 0){
        root = new Node(nullptr, rbTree.root);
        copy(root, rbTree.root);
    }
}

template<typename Key, typename Value>
RedBlackTree<Key, Value>& RedBlackTree<Key, Value>::operator=(const RedBlackTree<Key, Value> &rbTree) {
    if(&rbTree != this){
        destroy(root);
        root = nullptr;
        count = 0;
        if(rbTree.size() > 0){
            root = new Node(nullptr, rbTree.root);
            copy(root, rbTree.root);
        }
    }
    return *this;
}

template<typename Key, typename Value>
RedBlackTree<Key, Value>::~RedBlackTree() {
    destroy(root);
    root = nullptr;
}


template<typename Key, typename Value>
bool RedBlackTree<Key, Value>::insert(Key key, Value value) {
    if(search(key)){
        return false;
    }
    count ++;
    Node* x = new Node(key, value);
    root = insert(root, x); // BST insert

    while(x != root && isRed(x->parent)){
        if(x->parent == x->parent->parent->left){
            Node* y = sibling(x->parent);
            if(isRed(y)){
                x->parent->parent->isBlack = false;
                x->parent->isBlack = true;
                y->isBlack = true;

                x = x->parent->parent;
            } else {
                if(x == x->parent->right){
                    x = x->parent;
                    leftRotate(x);
                }
                x->parent->parent->isBlack = !x->parent->parent->isBlack;
                x->parent->isBlack = !x->parent->isBlack;
                rightRotate(x->parent->parent);
            }
        } else {
            Node* y = sibling(x->parent);
            if(isRed(y)){
                x->parent->parent->isBlack = false;
                x->parent->isBlack = true;
                y->isBlack = true;

                x = x->parent->parent;
            } else {
                if (x == x->parent->left){
                    x = x->parent;
                    rightRotate(x);
                }
                x->parent->parent->isBlack = !x->parent->parent->isBlack;
                x->parent->isBlack = !x->parent->isBlack;
                leftRotate(x->parent->parent);
            }
        }
    }

    root->isBlack = true;
    return true;
}


template<typename Key, typename Value>
bool RedBlackTree<Key, Value>::search(Key key) const {
    return find(root, key) != nullptr;
}


template<typename Key, typename Value>
int RedBlackTree<Key, Value>::size() const {
    return count;
}


template<typename Key, typename Value>
NodeT<Key, Value>* RedBlackTree<Key, Value>::getRoot() {
    return root;
}


template<typename Key, typename Value>
vector<Key> RedBlackTree<Key, Value>::keys() const {
    vector<Key> keys;
    vector<Value> values;
    pairs(keys, values);
    return keys;
}

template<typename Key, typename Value>
vector<Value> RedBlackTree<Key, Value>::values() const {
    vector<Key> keys;
    vector<Value> values;
    pairs(keys, values);
    return values;
}

template<typename Key, typename Value>
vector<Value> RedBlackTree<Key, Value>::search(Key key1, Key key2) const {
    vector<Key> keys;
    vector<Value> values;
    vector<Value> res;
    pairs(keys, values);

    for(int i = 0; i < keys.size(); i++){
        if(keys[i] >= key1 && keys[i] <= key2){
            res.push_back(values[i]);
        }
    }

    return res;
}

template<typename Key, typename Value>
bool RedBlackTree<Key, Value>::remove(Key key) {
    Node* z = find(root, key);
    if(z == nullptr){
        return false;
    }
    count --;

    // find the real node to remove
    Node* toRemove;
    if(z->left == nullptr || z->right == nullptr){
        toRemove = z;
    } else {
        toRemove = maximum(z->left);
    }

    if(toRemove->left == nullptr && toRemove->right == nullptr) { // maybe remove a black node
        if(toRemove == root){
            delete toRemove;
            root = nullptr;
            return true;
        }
        // assume it is deleted
        if(toRemove->isBlack){
            fixup(toRemove);
        }

    } else {
        // since toRemove has only one child, that child must be red, color it black
        // rotate toRemove node to the leaf, now toRemove is a red node
        if (toRemove->left != nullptr) {
            rightRotate(toRemove);
        } else {
            leftRotate(toRemove);
        }
        toRemove->parent->isBlack = true;
    }

    // copy value
    if (toRemove != z) {
        z->key = toRemove->key;
        z->value = toRemove->value;
    }

    // detach and remove
    Node* leaf = toRemove->parent;
    if(leaf->left == toRemove){
        leaf->left = nullptr;
    } else {
        leaf->right = nullptr;
    }
    delete toRemove;

    return true;
}


// private methods

template<typename Key, typename Value>
void RedBlackTree<Key, Value>::destroy(Node *node) {
    if(node == nullptr) {
        return;
    }
    destroy(node->left);
    destroy(node->right);
    delete node;
    count --;
}

template<typename Key, typename Value>
NodeT<Key, Value>* RedBlackTree<Key, Value>::find(Node *node, Key key) const {
    if(node == nullptr) {
        return nullptr;
    } else if(node->key == key) {
        return node;
    } else if(node->key > key) {
        return find(node->left, key);
    } else {
        return find(node->right, key);
    }
}

// BST insert
template<typename Key, typename Value>
NodeT<Key, Value>* RedBlackTree<Key, Value>::insert(Node *node, Node *h) {
    if(node == nullptr){
        return h;
    }
    else if (node->key < h->key){
        node->right = insert(node->right, h);
        node->right->parent = node;
    }
    else {
        node->left = insert(node->left, h);
        node->left->parent = node;
    }
    return node;
}

template<typename Key, typename Value>
void RedBlackTree<Key, Value>::leftRotate(Node *node) {
    Node* x = node->right;

    node->right = x->left;
    x->left = node;

    if(node == root){
        root = x;
    } else {
        x->parent = node->parent;
        if(node->parent->left == node) {
            node->parent->left = x;
        }
        else{
            node->parent->right = x;
        }
    }

    node->parent = x;

    if(node->right != nullptr){
        node->right->parent = node;
    }
}

template<typename Key, typename Value>
void RedBlackTree<Key, Value>::rightRotate(Node *node) {
    Node* x = node->left;
    node->left = x->right;
    x->right = node;

    if(node == root){
        root = x;
    } else {
        x->parent = node->parent;
        if(node->parent->left == node) {
            node->parent->left = x;
        }
        else{
            node->parent->right = x;
        }
    }

    node->parent = x;

    if(node->left != nullptr){
        node->left->parent = node;
    }
}

template<typename Key, typename Value>
bool RedBlackTree<Key, Value>::isRed(Node *node) {
    if(node == nullptr){
        return false;
    }
    return !node->isBlack;
}

template<typename Key, typename Value>
void RedBlackTree<Key, Value>::pairs(vector<Key>& keys, vector<Value>& values) const {
    inOrderTraversal(root, keys, values);
}

template<typename Key, typename Value>
void RedBlackTree<Key, Value>::inOrderTraversal(Node *node, vector<Key> &keys, vector<Value> &values) const {
    if(node != nullptr){
        inOrderTraversal(node->left, keys, values);

        keys.push_back(node->key);
        values.push_back(node->value);

        inOrderTraversal(node->right, keys, values);
    }
}

template<typename Key, typename Value>
void RedBlackTree<Key, Value>::copy(Node *node1, Node *node2) {
    if(node2->left != nullptr){
        node1->left = new Node(node1, node2->left);
        copy(node1->left, node2->left);
    }
    if(node2->right != nullptr){
        node1->right = new Node(node1, node2->right);
        copy(node1->right, node2->right);
    }
}

template<typename Key, typename Value>
NodeT<Key, Value>* RedBlackTree<Key, Value>::maximum(Node *node) {
    if(node->right == nullptr)
        return node;
    return maximum(node->right);
}

template<typename Key, typename Value>
void RedBlackTree<Key, Value>::fixup(Node* node) {
    while(node != root && !isRed(node)){
        if(node->parent->left == node){
            Node* y = node->parent->right;
            if(isRed(y)){
                y->isBlack = true;
                y->parent->isBlack = false;
                leftRotate(y->parent);
                y = node->parent->right;
            }
            if(!isRed(y->left) && !isRed(y->right)){
                y->isBlack = false;
                node = node->parent;
            } else {
                if(isRed(y->left)){
                    y->left->isBlack = true;
                    y->isBlack = false;
                    rightRotate(y);
                    y = y->parent;
                }
                y->isBlack = node->parent->isBlack;
                node->parent->isBlack = true;
                y->right->isBlack = true;
                leftRotate(node->parent);
                node = root;
            }
        } else {
            Node* y = node->parent->left;
            if(isRed(y)){
                y->isBlack = true;
                y->parent->isBlack = false;
                rightRotate(y->parent);
                y = node->parent->left;
            }
            if(!isRed(y->left) && !isRed(y->right)){
                y->isBlack = false;
                node = node->parent;
            } else {
                if(isRed(y->right)){
                    y->right->isBlack = true;
                    y->isBlack = false;
                    leftRotate(y);
                    y = y->parent;
                }
                y->isBlack = node->parent->isBlack;
                node->parent->isBlack = true;
                y->left->isBlack = true;
                rightRotate(node->parent);
                node = root;
            }
        }
    }
    if(node){
        node->isBlack = true;
    }
}

template<typename Key, typename Value>
NodeT<Key, Value> *RedBlackTree<Key, Value>::sibling(Node* node) {
    if(node == node->parent->left){
        return node->parent->right;
    }
    return node->parent->left;
}

