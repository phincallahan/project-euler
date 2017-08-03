#include<iostream>

using namespace std;

const short MONTHS[] = {3, 0, 3, 2, 3, 2, 3, 3, 3, 2, 3};

int main() {
    int count = 0;
    short curr = 1;
    for(int y = 1900; y <= 2000; y++) {
        for(int m = 0; m < 12; m++) {
            if(m == 1 && y % 4 == 0 && (y % 1000 != 0 || y % 400 == 0)) curr++;
            curr = (curr + MONTHS[m]) % 7;
            if(curr == 0 && y > 1900) count++;
        }
    }

    cout << count << '\n';
}