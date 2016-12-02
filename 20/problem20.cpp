#include<iostream>
#include<string>

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

int main() {
    string curr = "0";
    string fact = "1";
    for(int i = 0; i < 100; i++) {
        curr = add(curr, "1");
        fact = multiply(fact, curr);
    }

    int sum = 0;
    for(int i = 0; i < fact.length(); i++) {
        sum += fact[i] - '0';
    }
    
    cout << sum << "\n";
}