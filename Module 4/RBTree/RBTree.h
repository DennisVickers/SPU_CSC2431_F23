#ifndef RBTREE_H
#define RBTREE_H

enum Color {RED, BLACK};

struct Node {
    int data;
    bool color;
    Node *left, *right, *parent;

    Node(int data);
};

class RBTree {
public:
    RBTree();
    ~RBTree();
    void insert(int data);
    void remove(int data);
    void inorder();
    void levelOrder();

private:
    Node *root;
    void insertFix(Node *node);
    void deleteFix(Node *node);
    void rotateLeft(Node *node);
    void rotateRight(Node *node);
    Node* findMin(Node *node);
    Node* search(int n);
    void inorderHelper(Node *root);
    void levelOrderHelper(Node *root);
    void releaseMemory(Node *node);
};

#endif // RBTREE_H
