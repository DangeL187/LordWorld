#include <iostream>
#include <vector>
#include <string>
using namespace std;

auto map(string type, vector<auto> vals) {
    vector<auto> vals2;
    for (int i = 0, i < vals.size(), i++) {
        if (type == "int") {
            vals2.push_back(stoi(vals[i]));
        } else if (type == "string") {
            vals2.push_back(to_string(vals[i]));
        } else if (type == "char") {
            vals2.push_back(stoi(vals[i]));
        }
    }
}

int main() {
    //#define map(int, y) map(0, y) //fock it
    vector<int> v1;
    v1.push_back("1");
    v1.push_back("2");
    v1.push_back("3");
    vector<string> v2;
    v2.push_back("1");
    v2.push_back("2");
    v2.push_back("3");
    vector<char> v3;
    v3.push_back("a");
    v3.push_back("b");
    v3.push_back("c");
    cout << map("int", v1) << endl;
    cout << map("string", v2) << endl;
    cout << map("char", v3) << endl;
}
