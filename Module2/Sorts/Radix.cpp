#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <string>
using namespace std;

// Declare functions
void radixSort(vector<int> &list, int n, int max);
void printList(const vector<int> &list);
void createList(vector<int> &list, int listSize=5);
int getMax(const vector<int> &list);
int getDigit(int number, int position);

int main() {
    // Create a random list of integers between 1-200
    vector<int> list;
    createList(list, 20);

    cout << "Unsorted list: ";
    printList(list);

    radixSort(list, list.size(), getMax(list));

    cout << "Sorted list: ";
    printList(list);

    return 0;
}

/* Helper functions */
void printList(const vector<int> &list) {
    for (int num : list) {
        cout << num << " ";
    }
    cout << endl;
}

void createList(vector<int> &list, int listSize) {
    srand(time(0));
    for (int i=0; i<listSize; i++) {
        list.push_back((rand() % 100));
    }
}

// Function to get the maximum value in an array
int getMax(const vector<int> &list) {
    int max = list.at(0);
    for (int i = 1; i < list.size(); i++) {
        if (list.at(i) > max) {
            max = list.at(i);
        }
    }
    return max;
}

int getDigit(int number, int position) {
    string numStr = to_string(number);
    string retVal = numStr.substr(numStr.length() - 1 - position,1);

    return stoi(retVal);
}

void radixSort(vector<int> &list, int n, int max) {
    vector<vector <int>> bucket{{},{},{},{},{},{},{},{},{},{}};      //radix of decimal number is 10
    int maxDigits;
    int itemVal;
    int bucketIdx;

    maxDigits = to_string(max).length();

    int count;
    cout << "MaxDigits:" << maxDigits << endl;
    for (int i=0; i<maxDigits; i++) {
        for (int j=0; j<n; j++) {
            itemVal = list.at(j);
            bucketIdx = getDigit(itemVal, i);
            bucket.at(bucketIdx).push_back(itemVal);
        }

        count = 0;
        for(int k = 0; k<10; k++) {
            for (int num : bucket[k]) {
                list.at(count) = num;
                count++;
            }
            bucket[k].clear();
        }
    }
}
