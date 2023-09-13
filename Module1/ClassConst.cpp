#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Default constructor
    Person() {
       name = "Unknown";
       age = 0;
    }

    // Parameterized constructor
    Person(string name_in, int age_in) {
       name = name_in;
       age = age_in;
    }

    // Setter for name
    void setName(string newName) {
        name = newName;
    }

    // Getter for name
    string getName() {
        return name;
    }

    // Setter for age
    void setAge(int newAge) {
        if (newAge >= 0) {
            age = newAge;
        }
    }

    // Getter for age
    int getAge() {
        return age;
    }

    // Method to display details
    void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // Create an object of the Person class using the default constructor
    Person person1;
    person1.displayDetails();  // Output: Name: Unknown, Age: 0

    // Create another object using the parameterized constructor
    Person *PersonPtr = new Person("Alice", 30);
    PersonPtr->displayDetails();  // Output: Name: Alice, Age: 30

    // Modify the attributes using setters
    person1.setName("Bob");
    person1.setAge(25);
    person1.displayDetails();  // Output: Name: Bob, Age: 25
    
    delete PersonPtr;

    return 0;
}
