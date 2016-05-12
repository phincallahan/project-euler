#include <iostream>

using namespace std;

const int N = 100;
int main() {
   long sum_square = 0, square_sum = 0;
   for(int i = 0; i <= N; i++) {
       sum_square += i*i;
       square_sum += i;
    }


   cout << square_sum*square_sum - sum_square;
}
