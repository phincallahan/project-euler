#include <iostream>

using namespace std;

string add(string a, string b) {
    if(a.length() > b.length()) a.swap(b);
    a.insert(0, b.length() - a.length(), '0');

    string sum = a;
    int carry = 0;

    for(int i = a.length() - 1; i >= 0; i--) {
        int val = (a[i] - '0') + (b[i] - '0') + carry;
        carry = val/10;
        sum[i] = (val % 10) + '0';
    }

    if(carry > 0) {
        sum.insert(0, 1, carry + '0');
    }

    return sum;
}

const int MAX_LENGTH = 1000;

int main() {
    string a = "1", b = "1";
    int index = 2;
    while(b.length() < MAX_LENGTH) {
        string temp = b;
        b = add(a, b);
        a = temp;
        index++;
    }

    cout << index << "\n";
}