#include <iostream>
using namespace std;

void PointerAlloc() {
   int* ptr = new int;     // dynamically allocate an integer
   *ptr = 5;               // assign a value to the allocated memory
   cout << *ptr << endl;   // use the allocated memory
   delete ptr;             // deallocate the memory when done
   ptr = nullptr;          // set ptr to nullptr to indicate it no longer points to allocated memory
}

void ArrayAlloc() {
   int *array = new int[10];  // dynamically allocate an array of 10 integers

   for(int i = 0; i < 10; i++) {
      array[i] = i * i;       // initialize the array
   }

   cout << array[3] << endl; // use the allocated memory
   
   delete[] array;            // deallocate the array when done
   array = nullptr;           // prevent dangling pointer
}

int main() {
   
   PointerAlloc();
   
   ArrayAlloc();

   return 0;
}
