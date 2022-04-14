#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> v;
int a;
int b;
int c;

int vec(int X) {
    a = X;
    b = a;
    c = b;
    v.push_back(c);
}

int main() {
    int arr[10] = {1, 1, 1, 2, 2, 6, 7, 8, 9, 10};
    arr.erase(arr.begin() + 9);
}
