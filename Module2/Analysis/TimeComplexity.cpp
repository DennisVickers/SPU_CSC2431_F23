#include <iostream>
#include <vector>
using namespace std;

int constantTime(vector<int> *input) {
   int ops = 0;

   // Do something   
   ops++;
   
   return ops;
}

int linearTime(vector<int> *input) {
   int ops=0;
   int n=input->size();
   cout << "n:" << n << endl;
   
   for (int i = 0; i < n; i++) {
      // Do something
      ops++;
   }
   
   return ops;
}

int quadraticTime(vector<int> *input) {
   int ops=0;
   int n=input->size();
   
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; ++j) {
         // Do something
         ops++;
      }
   }
   
   return ops;
}

int logrithmicTime(vector<int> *input, int target) {
   // This is a binary search
   int ops=0;
   int n=input->size();
   int low = 0;
   int mid;
   int high = n - 1;
   
   while (low <= high) {
      mid = low + (high - low) / 2;
      ops++;
      if (input->at(mid) == target) {
         ops++;
         return ops;
      }
      ops++;
      if (input->at(mid) < target) {
         low = mid + 1;
         ops++;
      } else {
         high = mid - 1;
         ops++;
      }
   }
   
   return ops;
}

int main() {
   vector<int> input;
   int n;
   int ops;
   
   cout << "How many input value are there? ";
   cin >> n;
   cout << "Input = " << n << endl;
   
   n = (n > 0) ? n : 1;
   
   // Create an vector of integers
   for (int i=0; i<n; i++) {
      input.push_back(i+1);
   }

   // Constant Time Complexity O(1)
   ops = constantTime(&input);
   cout << "Constant operations: " << ops << endl;
    
   // Linear Time Complexity O(n)
   ops = linearTime(&input);
   cout << "Linear operations: " << ops << endl;
    
   // Quadratic Time Complexity O(n^2)
   ops = quadraticTime(&input);
   cout << "Quadratic operations: " << ops << endl;
    
    
   // Logrithmic Time Complexity O(log n)
   ops = logrithmicTime(&input, input.size());
   cout << "Logrithmic operations: " << ops << endl;

   return 0;
}
