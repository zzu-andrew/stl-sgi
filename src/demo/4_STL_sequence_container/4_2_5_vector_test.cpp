// filename: 4vector-test.cpp

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

inline void printInfo(vector<int> &iv) {
    cout << "size=" << iv.size() << " capacity=" << iv.capacity() << endl;

}

void printVector(vector<int> iv) {
    for (int i : iv) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int i;
    vector<int> iv(2, 9);
    printInfo(iv);

    for (int j = 1; j < 5; j++) {
        iv.push_back(j);
        printInfo(iv);
    }

    printVector(iv);

    iv.push_back(i);
    printInfo(iv);
    printVector(iv);

    iv.pop_back();
    iv.pop_back();
    printInfo(iv);

    iv.pop_back();
    printInfo(iv);

    vector<int>::iterator ivite = find(iv.begin(), iv.end(), 1);
    if (ivite!=iv.end())
        iv.erase(ivite);
    printInfo(iv);
    printVector(iv);

    ivite = find(iv.begin(), iv.end(), 2);
    if (ivite!=iv.end())
        iv.insert(ivite, 3, 7);
    printInfo(iv);
    printVector(iv);

    iv.clear();
    printInfo(iv);
}