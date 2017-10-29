#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    for(int x = 1, y = 1; x < 4000000;) {
        if(x%2 == 0)
            sum += x;

        int temp = x;
        x = x+y;
        y = temp;
    }

    cout << sum;
}
