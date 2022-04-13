#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int out = 0 - 1;
	int outy = 0 - 2;
    float mx = 3;
    float my = 4;
    float condx = mx/1 + 64;
    float condy = my/1 + 64;

    cout << out << " " << outy << endl;
    cout << mx << " " << my << endl;
    cout << condx << " " << condy << endl;

    //mx/1 <= out && out <= condx && my/1 <= outy && outy <= condy
    //3 <= -1 <= 67 && 4 <= -2 <= 68
    //3 <= 4 && 4 <= 67 && 4 <= 5 && 5 <= 68
    if (400/1 <= 336 <= 464 && 400/1 <= 352 <= 464) {
        cout << "SEX" << endl;
    }
    if (300/1 <= 336 <= 364 && 300/1 <= 352 <= 364) {
        cout << "SEX2" << endl;
    }
}
