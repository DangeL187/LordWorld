#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Monster {
public:
    int mx = 0;
    Monster(int get_x) {
         mx = get_x;
    }
    int getX() {
        return mx;
    }
};

vector<Monster> v;

void createInt(int i) {
    int x = i;
    v.push_back(x);
}

void create(Monster i) {
    Monster x = i;
    v.push_back(x);
}

int main() {
    create(Monster(1));
    create(Monster(2));
    cout << v[0].getX() << " " << v[1].getX() << endl;
}
