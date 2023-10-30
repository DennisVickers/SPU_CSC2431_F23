#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class HashTable {
public:
   HashTable(int size);
   ~HashTable();

   void insert(const string key, const string value);
   bool remove(const string key);
   bool search(const string key, string &value) const;
   void display() const;

private:
   int size;
   vector<vector<pair<string, string>>> table;
   int hashFunction(const string &key) const;
};


#endif //HASHTABLE_HASHTABLE_H
