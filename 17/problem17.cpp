#include <iostream>

using namespace std;

const int LEN_HUN = 7;
const int LEN_THO = 8;
const int ONES[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
const int TENS[] = {3, 6, 6, 5, 5, 5, 7, 6, 6};

int count_letters(int n) {
    if(n == 1000) return LEN_THO + ONES[1];

    int len = 0;
    int hun = (n % 1000) / 100;
    int ten = (n % 100) / 10;
    int one = n % 10;

    if(hun > 0) {
        len += LEN_HUN + ONES[hun] + (n % 100 != 0) * 3;
    } 

    if(ten >= 2) {
        len += TENS[ten - 1] + ONES[one];
    } else if(one > 0 || ten > 0) {
        len += ONES[one + ten * 10];
    }

    return len;
}

int main() {
    int sum = 0;
    for(int i = 1; i <= 1000; i++) {
        sum += count_letters(i);
    }

    cout << sum << "\n";
}