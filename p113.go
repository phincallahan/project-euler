package main

import "fmt"

const N, D int = 100, 9 
func main() {
	non_bouncy, asc, desc := D, make([]int, D), make([]int, D)
	for i := 0; i < D; i++ { 
		asc[i], desc[i] = 1, 1
	}

	for k := 1; k < N; k++ {
		next_asc, next_desc := make([]int, D), make([]int, D)
		for i := 0; i < D; i++ {
			next_asc[i] += 1
			for j := i; j < D; j++ {
				next_asc[j] += asc[i]
				next_desc[i] += desc[j]
			}
		}

		asc, desc = next_asc, next_desc
		for i := 0; i < D; i++ { 
			non_bouncy += asc[i] + desc[i] 
		}
	}

	fmt.Println(non_bouncy - (N - 1) * D)
}