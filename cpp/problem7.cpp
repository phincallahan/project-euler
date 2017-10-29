#include <iostream>

using namespace std;

const int N = 10001;
int main() {
    int curr_i = 0;
    int num = 2;
    int primes[N]; 

    while(curr_i < N) {
        bool is_prime = true;
        for(int i = 0; i < curr_i; i++)
           if(num % primes[i] == 0) {
               is_prime = false;
               break;
           }
        
        if(is_prime)
            primes[curr_i++] = num;

        num++;
    }

    cout << primes[N-1];
}
