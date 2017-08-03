#include <iostream>
#include <string>

using namespace std;

const int lim = 10e2;
int isPalindrome(int n);

int main() {
    int max = 0;        

    for(int i = 100; i < lim; i++)
        for(int j = i; j < lim; j++) 
            if(isPalindrome(i*j) && i*j > max) {
                max = i*j;
            }
    
    cout << max;
}

int isPalindrome(int num) {
    string str = to_string(num); 

    for(int i = 0; i < str.length(); i++) {
        if(str[i] != str[str.length() - i - 1]) {
            return false;
        }
    }

    return true;
}
