#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Create a vector of integers
    vector<int> ages = {1, 2, 3, 4, 5};

    // Add an element to the end of the vector
    ages.push_back(20);

    // Access elements using the at() method
    cout << "Element at index 2: " << ages.at(2) << endl;

    // Access elements using the [] operator
    cout << "Element at index 4: " << ages[4] << endl;

    // Get the size of the vector
    cout << "Size of the vector: " << ages.size() << endl;

    // Iterate over the vector using a range-based for loop
    cout << "Elements in the vector: ";
    for (int age : ages) {
        cout << age << " ";
    }
    cout << endl;

    // Remove the last element
    ages.pop_back();
    cout << "Size after pop_back: " << ages.size() << endl;

    // Insert an element at a specific position
    ages.insert(ages.begin() + 1, 10);
    cout << "Element at index 1 after insert: " << ages[1] << endl;

    // Erase an element at a specific position
    ages.erase(ages.begin() + 2);
    cout << "Element at index 2 after erase: " << ages[2] << endl;

    // Clear all elements in the vector
    ages.clear();
    cout << "Size after clear: " << ages.size() << endl;

    return 0;
}