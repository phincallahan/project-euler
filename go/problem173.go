package main 

import	"fmt"

const N = 1000000
func main() {
	var exact [N]int
	for i := 2; i <= N; i++ {
		s, j := i, i
		for 4 * s <= N {
			exact[4 * s - 2] += 1
			j += 2
			s += j
		}
	}

	sum := 0
	for i := 0; i < N; i++ { sum += exact[i] }
	fmt.Println(sum)
}