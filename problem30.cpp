#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int power_sum(vector<int> dig, int power) {
    int sum = 0;
    for(int i = 0; i < dig.size(); i++) {
        sum += dig[i] * pow(i, power);
    }

    return sum;
}

vector<int> get_digits(int sum) {
    vector<int> digits(10, 0);
    while(sum > 0) {
        int dig = sum % 10;
        digits[dig] += 1;
        sum = sum/10;
    }

    return digits;
}

int check_digits(vector<int> digits, int dig_left, int sum) {
    int curr_sum = power_sum(digits, 5);
    vector<int> sum_digits = get_digits(curr_sum);


    bool is_eq = true;
    for(int i = 0; i < digits.size(); i++) {
        if(digits[i] != sum_digits[i]) {
            is_eq = false;
            break;
        }
    }

    if(!is_eq || curr_sum == 1) curr_sum = 0;

    if(dig_left == 0) {
        return sum + curr_sum;
    } else {
        for(int i = 0; i < digits.size(); i++) {
            digits[i] += 1;
            curr_sum += check_digits(digits, dig_left-1, sum);
            digits[i] -= 1;

            if(digits[i] > 0) break;
        }

        return sum + curr_sum;
    }
}

int main() {
    vector<int> base_dig(10, 0);
    cout << check_digits(base_dig, 8, 0) << '\n';
}