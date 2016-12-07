#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>

using namespace std;

string merge_mask(string a, string b) {
    for(int i = 0; i < 9; i++) {
        if(a[i] != '0') b.insert(i, 1, '0');
    }

    return b;
}

bool n_perm(string & val) { return next_permutation(val.begin(), val.end()); }
bool p_perm(string & val) { return prev_permutation(val.begin(), val.end()); }

int pandigital_product(int digits1, int digits2, unordered_set<string> & counted) {
    int sum = 0;

    string mask1 = string(9 - digits1, '0');
    for(int i = 1; i <= digits1; i++) mask1 += i + '0';
    
    do {
        string first(digits1, ' ');
        for(int i = 0; i < 9; i++) {
            if(mask1[i] != '0') 
                first[(mask1[i] - 1) - '0'] = (i+1) + '0';
        }

        string mask2 = string(digits2, '1') + string(9 - digits1 - digits2, '0');

        do {
            string mask2_full = merge_mask(mask1, mask2);
            string second = "";

            for(int i = 0; i < 9; i++) {
                if(mask2_full[i] != '0') 
                    second += (i+1) + '0';
            }

            if(to_string(stoi(second) * stoi(first)).length() > 9 - digits1 - digits2)
                break;

            do {
                string third = to_string(stoi(first) * stoi(second));

                if(third.length() > 9 - digits1 - digits2) break;

                if(counted.count(third) != 0) continue;
                else counted.insert(third);

                string needed;
                sort(third.begin(), third.end());
                for(int i = 0; i < 9; i++) {
                    if(mask2_full[i] == '0' && mask1[i] == '0') 
                        needed += (i+1) + '0';
                } 
                    
                if(needed == third) {
                    int prod = stoi(first) * stoi(second);
                    sum += prod;
                }

            } while(n_perm(second));
        } while(p_perm(mask2));
    } while(n_perm(mask1));

    return sum;
}


int main() {
    int sum = 0;
    unordered_set<string> counted;
    sum += pandigital_product(2, 3, counted);
    sum += pandigital_product(1, 4, counted);
    cout << sum << endl;
}