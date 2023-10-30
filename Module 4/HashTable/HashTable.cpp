#include "HashTable.h"

HashTable::HashTable(int size) : size(size), table(size, vector<pair<string, string>>()) {}

HashTable::~HashTable() {
   // Vector will automatically deallocate its memory
}

int HashTable::hashFunction(const string &key) const {
   int hash = 0;
   for (char c : key) {
      hash = (hash * 31 + c) % size;
   }
   return hash;
}

void HashTable::insert(const string key, const string value) {
   int index = hashFunction(key);
   for (auto &pair : table[index]) {
      if (pair.first == key) {
         pair.second = value;  // Update value if key already exists
         return;
      }
   }
   table[index].emplace_back(key, value);
}

bool HashTable::remove(const string key) {
   int index = hashFunction(key);
   for (auto it = table[index].begin(); it != table[index].end(); ++it) {
      if (it->first == key) {
         table[index].erase(it);
         return true;
      }
   }
   return false;
}

bool HashTable::search(const string key, string &value) const {
   int index = hashFunction(key);
   for (const auto &pair : table[index]) {
      if (pair.first == key) {
         value = pair.second;
         return true;
      }
   }
   return false;
}

void HashTable::display() const {
   for (int i = 0; i < size; ++i) {
      cout << "Bucket " << i << ":";
      for (const auto &pair : table[i]) {
         cout << " (" << pair.first << ", " << pair.second << ")";
      }
      cout << endl;
   }
}
