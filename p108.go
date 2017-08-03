package main

import (
	"fmt"
)

func main() {
	count, max_i := make(map[int]int), 0;

	for x := 1;; x++ {
		for y := 1; y <= x; y++ {
			if (x * y) % (x + y) == 0 {
				i := (x * y) / (x + y)
				count[i] += 1
				if count[i] > count[max_i] {
					max_i = i
					fmt.Println(count[max_i])
				}
			}
		}

		if count[max_i] >= 1000 { break }
	}



	fmt.Println(max_i)
}
