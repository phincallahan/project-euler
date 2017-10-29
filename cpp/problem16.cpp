#include <iostream>
#include <string>

using namespace std;

string add(string a, string b);
string multiply(string a, string b) {
    if(a.length() > b.length()) a.swap(b);

    string product = "0";
    for(int i = b.length() - 1; i >= 0; i--) {
        string temp = a;
        int carry = 0;

        for(int j = a.length() - 1; j >= 0; j--) {
            int val = (temp[j] - '0') * (b[i] - '0') + carry;
            carry = val / 10;
            temp[j] = (val % 10) + '0';
        }

        if(carry > 0) {
            temp.insert(0, 1, carry + '0');
        }

        temp.insert(temp.length(), b.length() - 1 - i, '0');
        
        product = add(product, temp);
    }

    return product;
}

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

string large_power(string x, int n) {
    if(n == 0) {
        return "1";
    } else if(n == 1) {
        return x;
    } else if(n % 2 == 0) {
        return large_power(multiply(x,x), n/2);
    } else {
        return multiply(large_power(multiply(x,x), (n-1)/2), x);
    }
}

int main() {
    string power = large_power("2", 1000);
    int digit_sum = 0;

    for(int i = 0; i < power.length(); i++) {
        digit_sum += power[i] - '0';
    }

    cout << power << "\n";
    cout << digit_sum << "\n";

    return 1;
}
