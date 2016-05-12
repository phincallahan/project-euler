#include <iostream>

using namespace std;

int main() {
    int div = 1;
    long num = 600851475143;

    while(num != 1) {
        div++;
        while(num % div == 0) {
            num /= div;
            cout << div << "\n";
        } 
    }

    cout << div;
}
