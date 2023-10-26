#include "AVLTree.h"

// Node constructor
Node::Node(int key) : key(key), height(1), left(nullptr), right(nullptr) {}

// AVLTree constructor and destructor
AVLTree::AVLTree() : root(nullptr) {}
AVLTree::~AVLTree() {
   deleteTree(root);
}

// Public functions
void AVLTree::insert(int key) {
   root = insert(root, key);
}

void AVLTree::remove(int key) {
   root = remove(root, key);
}

bool AVLTree::search(int key) const {
   return (search(root, key));
}

void AVLTree::inorderTraversal() const {
   inorderTraversal(root);
   cout << endl;
}

// Private functions
Node *AVLTree::insert(Node *newNode, int key) {
   // Regular BST node insert operation
   if (newNode == nullptr) {
      return (new Node(key));
   }

   if (key < newNode->key) {
      newNode->left = insert(newNode->left, key);
   } else if (key > newNode->key) {
      newNode->right = insert(newNode->right, key);
   } else {
      return newNode; // Duplicates are not allowed
   }

   // Update the height
   newNode->height = 1 + max(getHeight(newNode->left), getHeight(newNode->right));
   // Get balance factor
   int balance = getBalanceFactor(newNode);

   // Re-balance if necessary
   if (balance > 1 && getBalanceFactor(newNode->left) >= 0) { // LL Rotation
      return rotateRight(newNode);
   }
   if (balance > 1 && getBalanceFactor(newNode->left) < 0) { // RL Rotation
      newNode->left = rotateLeft(newNode->left);
      return rotateRight(newNode);
   }
   if (balance < -1 && getBalanceFactor(newNode->right) <= 0) {  // RR Rotation
      return rotateLeft(newNode);
   }
   if (balance < -1 && getBalanceFactor(newNode->right) > 0) { // LR Rotation
      newNode->right = rotateRight(newNode->right);
      return rotateLeft(newNode);
   }

   return newNode;  // New root of the subtree
}

Node *AVLTree::remove(Node *remNode, int key) {
   // Regular BST node removal operation
   if (remNode == nullptr) {
      return (remNode);  // Nothing to remove
   }

   if (key < remNode->key) {
      remNode->left = remove(remNode->left, key);
   } else if (key > remNode->key) {
      remNode->right = remove(remNode->right, key);
   } else {
      if ((remNode->left == nullptr) || (remNode->right == nullptr)) {
         Node *temp = remNode->left ? remNode->left : remNode->right;
         if (temp == nullptr) {
            temp = remNode;
            remNode = nullptr;
         } else {
            *remNode = *temp;
         }
         delete temp;
      } else {
         Node *temp = remNode->right;
         while (temp->left != nullptr) {
            temp = temp->left;
         }
         remNode->key = temp->key;
         remNode->right = remove(remNode->right, temp->key);
      }
   }

   if (remNode == nullptr) {
      return remNode;
   }

   // Update the height
   remNode->height = 1 + max(getHeight(remNode->left), getHeight(remNode->right));
   // Get balance factor
   int balance = getBalanceFactor(remNode);

   // Rebalance the tree
   if (balance > 1 && getBalanceFactor(remNode->left) >= 0) { // LL Rotation
      return rotateRight(remNode);
   }
   if (balance > 1 && getBalanceFactor(remNode->left) < 0) { // RL Rotation
      remNode->left = rotateLeft(remNode->left);
      return rotateRight(remNode);
   }
   if (balance < -1 && getBalanceFactor(remNode->right) <= 0) {  // RR Rotation
      return rotateLeft(remNode);
   }
   if (balance < -1 && getBalanceFactor(remNode->right) > 0) { // LR Rotation
      remNode->right = rotateRight(remNode->right);
      return rotateLeft(remNode);
   }

   return remNode;
   /*
    * Explanation
    * 1. Standard BST Deletion: If the key to be removed is smaller than the subtree root's key, then it lies
    *    in the left subtree. Similarly, if the key to be deleted is larger, then it lies in the right subtree.
    *    If the key to be deleted is equal to the root's key, then this is the node to be deleted.
    * 2. Balancing: After the removal, update the height of the current node, and get its balance factor.
    *    Depending on the balance factor, decide which rotation needs to be performed to balance the tree.
    * 3. Rotate Functions: rotateRight and rotateLeft are utility functions used to perform right and left rotations.
    */
}

bool AVLTree::search(Node *currNode, int key) const {
   if (currNode == nullptr) {
      return (false);       // Base case, key not found
   }
   if (key < currNode->key) {  // Search the left branch
      return (search(currNode->left, key));
   }
   if (key > currNode->key) {  // Search the right branch
      return search(currNode->right, key);
   }

   return (true);  // Base case, key found
}

void AVLTree::inorderTraversal(Node *currNode) const {
   if (currNode == nullptr) {
      return;  // Base case, got to the end of the tree
   }
   // traverse the left branch
   inorderTraversal(currNode->left);
   // touch the root of the subtree
   cout << currNode->key << " ";
   // traverse the right branch
   inorderTraversal(currNode->right);
}

int AVLTree::getHeight(Node *subjNode) const {
   return ((subjNode != nullptr) ? subjNode->height : 0);
}

int AVLTree::getBalanceFactor(Node *subjNode) const {
   return (getHeight(subjNode->left) - getHeight(subjNode->right));
}

Node *AVLTree::rotateLeft(Node *onNode) {
   Node *newParent = onNode->right;
   onNode->right = newParent->left;
   newParent->left = onNode;

   onNode->height = 1 + max(getHeight(onNode->left), getHeight(onNode->right));
   newParent->height = 1 + max(getHeight(newParent->left), getHeight(newParent->right));

   return newParent;
}

Node *AVLTree::rotateRight(Node *subjNode) {
   Node *newParent = subjNode->left;
   subjNode->left = newParent->right;
   newParent->right = subjNode;

   subjNode->height = 1 + max(getHeight(subjNode->left), getHeight(subjNode->right));
   newParent->height = 1 + max(getHeight(newParent->left), getHeight(newParent->right));

   return newParent;
}

// Recursive function to delete all nodes in the tree
void AVLTree::deleteTree(Node *currNode) {
   if (currNode == nullptr) return;  // Base case

   deleteTree(currNode->left); // Follow the left path
   deleteTree(currNode->right); // Follow the right path
   delete currNode;  // Delete the current node (leaf)
}