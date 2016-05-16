#include <iostream>

using namespace std;

const int N = 21;
int main() {
   long path_len[N][N] = {0};
   path_len[0][0] = 1;
   
   for(int i = 1; i < 2*N-1; i++) {
       int k = i < N ? 0 : i-N+1;

       for(int j = k; j <= i-k; j++) {
           long u_count = j > 0 ? path_len[j-1][i-j] : 0;
           long l_count = j < i ? path_len[j][i-j-1] : 0;
           cout << j << "," << i-j << "\n";
           
           path_len[j][i-j] = l_count + u_count;
           cout << l_count << "," << u_count << "\n\n";
       }
   }

   cout << path_len[N-1][N-1];
}
