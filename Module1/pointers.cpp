/* Basic pointer syntax
int x = 10;
int *p;          // Declare an integer pointer
p = &x;          // Assign the address of x to p
*/

/* reference syntax
int x = 10;
int &ref = x;
*/

/* Dereferencing
int value = *p;
*/

/* Nullability
int *p = nullptr;
*/

/* Address of opeator
int *addr = &p; // Pointer
int *addr = &ref; // Reference
*/

/* Reassignment
int x = 10;
int *p;
p = &x;
int y = 20;
p = &y;  // p now points to y
*/

/* Pointer arithmetic
int arr[5] = {1, 2, 3, 4, 5};
int *p = arr;    // p points to the first element of the array
p++;             // p now points to the second element
*/

/* Pointers and Functions
void modifyValue(int *p) {
    *p = 20;
}

int main() {
    int x = 10;
    modifyValue(&x);  // x will be changed to 20
    return 0;
}
*/

/* Pointers to Pointers
int x = 10;
int *p = &x;
int **pp = &p;   // pp is a pointer to a pointer to an int
*/

/* Dynamic Memory Allocation 
int *p = new int;  // Allocates an integer in the heap and returns its address
*p = 10;           // Assigns 10 to the allocated integer
delete p;          // Deallocates the memory
*/


