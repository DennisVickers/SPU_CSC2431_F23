#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
   int key;
   int height;
   Node *left;
   Node *right;
   Node(int key);
};

class AVLTree {
public:
   AVLTree();
   ~AVLTree();

   void insert(int key);
   void remove(int key);
   bool search(int key) const;
   void inorderTraversal() const;

private:
   Node *root;

   Node *insert(Node *node, int key);
   Node *remove(Node *node, int key);
   bool search(Node *node, int key) const;
   void inorderTraversal(Node *node) const;

   int getHeight(Node *node) const;
   int getBalanceFactor(Node *node) const;
   Node *rotateLeft(Node *node);
   Node *rotateRight(Node *node);
   void deleteTree(Node*);
};

#endif //AVLTREE_AVLTREE_H
