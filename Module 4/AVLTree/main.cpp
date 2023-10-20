#include "AVLTree.h"

int main() {
   AVLTree tree;

   tree.insert(20);
   tree.insert(15);
   tree.insert(30);
   tree.insert(10);
   tree.insert(5);

   tree.inorderTraversal(); // Should print: 5 10 15 20 30

   tree.remove(15);

   tree.inorderTraversal(); // Should print: 5 10 20 30

   cout << "Search 20: " << (tree.search(20) ? "Found" : "Not Found") << endl;
   cout << "Search 15: " << (tree.search(15) ? "Found" : "Not Found") << endl;

   return 0;
}