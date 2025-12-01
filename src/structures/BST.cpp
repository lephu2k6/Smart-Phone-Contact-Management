#include "BST.h"
#include <iostream>
using namespace std;

BST::BST() { root = nullptr; }
BST::~BST() { clear(root); }

void BST::clear(Node* node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

BST::Node* BST::insert(Node* node, const Contact &c) {
    if (!node) return new Node{c, nullptr, nullptr};
    if (c.getName() < node->data.getName())
        node->left = insert(node->left, c);
    else
        node->right = insert(node->right, c);
    return node;
}

void BST::insert(const Contact &c) { root = insert(root, c); }

BST::Node* BST::findMin(Node* node) {
    while (node && node->left) node = node->left;
    return node;
}

BST::Node* BST::remove(Node* node, const string &name) {
    if (!node) return nullptr;
    if (name < node->data.getName())
        node->left = remove(node->left, name);
    else if (name > node->data.getName())
        node->right = remove(node->right, name);
    else {
        if (!node->left) { Node* r = node->right; delete node; return r; }
        if (!node->right) { Node* l = node->left; delete node; return l; }
        Node* minNode = findMin(node->right);
        node->data = minNode->data;
        node->right = remove(node->right, minNode->data.getName());
    }
    return node;
}

void BST::remove(const string &name) { root = remove(root, name); }

Contact* BST::search(Node* node, const string &name) {
    if (!node) return nullptr;
    if (name == node->data.getName()) return &node->data;
    if (name < node->data.getName()) return search(node->left, name);
    return search(node->right, name);
}

Contact* BST::search(const string &name) { return search(root, name); }

void BST::inorder(Node* node) {
    if (!node) return;
    inorder(node->left);
    node->data.print();
    inorder(node->right);
}

void BST::printInorder() { inorder(root); }

void BST::updateName(const string &oldName, const string &newName){
    Contact* c = search(oldName);
    if(!c){ cout<<"Contact not found!\n"; return; }
    Contact temp = *c;
    remove(oldName);
    temp.setName(newName);
    insert(temp);
    cout<<"Name updated!\n";
}
