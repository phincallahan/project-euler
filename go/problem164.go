package main

import (
	"fmt"
)

func main() {
	var count [10][10]uint64

	// Initialize count
	for i := 0; i <= 9; i++ {
		for j := 0; j + i <= 9; j++ {
			count[i][j] = uint64(9 - i - j)
		}
	}

	for k := 4; k <= 20; k++ {
		var temp [10][10]uint64

		// Actuall DP part
		for i := 0; i < 10; i++ {
			for j := 0; j + i < 10; j++ {
				for k := 0; k + i + j < 10; k++ {
					temp[j][k] += count[i][j]
				}
			}
		}

		// copy array
		for i := 0; i < 10; i++ {
			for j := 0; j < 10; j++ {
				count[i][j] = temp[i][j]
			}
		}
	}

	// Sum array
	var sum uint64 = 0
	for i := 0; i < 10; i++ {
		for j := 0; j < 10; j++ {
			sum += count[i][j]
		}
	}

	fmt.Println(sum)
}
