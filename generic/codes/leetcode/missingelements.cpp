#include <iostream>
#include <vector>
#include <numeric> // for std::iota

using namespace std;

int main() {
    int n = 10; // Example value of n
    std::vector<int> values(n);

    // Populate the vector with values from 1 to n
    std::iota(values.begin(), values.end(), 1);

    // Output the populated vector
    for (int value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    vector<int> arr2; //{ 10, 15, 20, 20, 25, 30, 35 };
    arr2.push_back(10);
    arr2.push_back(11);
    arr2.push_back(12);
    arr2.push_back(13);
    arr2.push_back(14);
    arr2.push_back(15);
    arr2.push_back(16);
    arr2.push_back(17);
    arr2.push_back(18);
    arr2.push_back(20);


    cout << "The position of 21 using lower_bound "
            "(in multiple occurrence case) : ";
    vector<int>::iterator it = lower_bound(arr2.begin(), arr2.end(), 16);
    cout << (it == arr2.end());
    arr2.erase(it);

    cout << endl;
    for (int aval : arr2) {
        std::cout << aval << " ";
    }

    return 0;
}
