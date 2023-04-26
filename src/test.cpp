#include <iostream>
#include <vector>
#include <array>
#include <memory>
using namespace std;

int ar1[9] = {0, 1, 2, 0, 1, 2, 2, 1, 0};
int ar2[9] = {};

int a1[27] = {2, 0, 1, 0, 1, 0, 2, 1, 2};
int a2[27] = {};

int b9[9] = {};
int b27[27] = {};

void setImagesToHotbar() {
    for (int i = 0; i < 9; i++) {
        if (ar1[i] == 1) { //Cold Snap
            ar2[i] = -1;
        }
        else if (ar1[i] == 2) { //Cold Snap2
            ar2[i] = -2;
        }
        else {
            ar2[i] = -13;
        }
    }
}

void setImagesToSpellsInventory() {
    for (int i = 0; i < 27; i++) {
        if (a1[i] == 1) { //Cold Snap
            a2[i] = -1;
        }
        else if (a1[i] == 2) { //Cold Snap2
            a2[i] = -2;
        }
        else {
            a2[i] = -13;
        }
    }
}

void setImages(int size, auto& arr1, auto& arr2) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] == 1) { //Cold Snap
            arr2[i] = -1;
        }
        else if (arr1[i] == 2) { //Cold Snap2
            arr2[i] = -2;
        }
        else {
            arr2[i] = -13;
        }
    }
}

int main() {
    /*for (auto& i: ar1) {
        cout << "ar1: " << i << endl;
    }
    cout << endl;
    for (auto& i: a1) {
        cout << "a1: " << i << endl;
    }*/
    setImagesToHotbar();
    setImagesToSpellsInventory();
    cout << endl;
    for (auto& i: ar2) {
        cout << "#ar2: " << i << endl;
    }
    cout << endl;
    for (auto& i: a2) {
        cout << "#a2: " << i << endl;
    }

    setImages(9, ar1, b9);
    cout << endl;
    for (auto& i: b9) {
        cout << "#b9: " << i << endl;
    }
    setImages(27, a1, b27);
    cout << endl;
    for (auto& i: b27) {
        cout << "#b27: " << i << endl;
    }

    return 0;
}
