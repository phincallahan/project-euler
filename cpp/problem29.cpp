#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;
int main() {
    int distinct = (MAX-1)*(MAX-1);
    vector<short> is_power (MAX, 0);
    
    for(short i = 2; i*i <= MAX; i++) {
        short base = i*i;
        short power = 2;
        while(base <= MAX) {
            if(power > is_power[base-1]) is_power[base-1] = power++;
            base *= i;
        }
    }
    
    for(short i = 2; i <= MAX; i++) {
        if(is_power[i-1]) {
            for(short j = 2; j <= MAX; j++) {
                for(short k = 1; k < is_power[i-1]; k++) {
                    short num = is_power[i-1]*j;
                    if(num % k == 0 && num/k <= MAX && num/k >= 2) {
                        distinct--;
                        break;
                    }
                }
            } 
        }
    }

    cout << distinct << '\n';
}