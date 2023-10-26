#include <iostream>
using namespace std;

struct Location {
    int x, y;
    
    void setValues(int x, int y) {
        this->x = x;
        this->y = y;
    }
    
    void display() {
        cout << "Location(" << x << ", " << y << ")" << endl;
    }
};

// Nested Structs
struct Line {
   Location start;
   Location end;
};

void printLocation(Location l) {
   cout << "(" << l.x << ", " << l.y << ")" << endl;
}

int main() {
   // Using a struct
   Location l1;
   l1.setValues(1,2);
   l1.display();
   
   // Initializing a struct
   Location l2 = {4,5};
   l2.display();
   
   // Nested
   Line line1;
   line1.start = {6,7};
   line1.start.display();
   
   // Array of Structs
   Location locations[5];
   locations[0].setValues(9,10);
   locations[0].display();
   
   // Passing to function
   printLocation(l1);
   
   // Pointer to Struct
   Location *ptr = &l1;
   ptr->x = 20;
   ptr->y = 21;
   ptr->display();
   
   return 0;
}

