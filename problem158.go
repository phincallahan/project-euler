package main

import "fmt"

const N = 26 
var D [N + 1][N + 1]int

func choose(n, from int) int {
	if n > from || n < 0 || from < 0 {
		return 0;
	} else if D[n][from] > 0 {
		return D[n][from]
	} else {
		D[n][from] = choose(n, from - 1) + choose(n - 1, from - 1)
		return D[n][from]
	}
}

func main() {
	for i := 0; i < N; i++ { D[i][i], D[0][i] = 1, 1; }

	max := 0
	for n := 3; n <= N; n++ {
		s := 0
		for i := 0; i < n; i++ {
			for j := 0; j < N; j++ {
				for k := 0; k < i; k++ {
					s += choose(i - k - 1, j - 1) *
						 choose(k, N - j) *
						 choose(n - i, N - j - k)
				}
			}
		}

		if s > max { max = s }
	}

	fmt.Println(max)
}