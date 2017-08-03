package main 

import (
	"github.com/alex-ant/gomath/gaussian-elimination"
	"github.com/alex-ant/gomath/rational"
	"log"
)


type polynomial func(int) rational.Rational
func nr(x int) rational.Rational { return rational.New(int64(x), 1) }

func get_polynomial(coef []rational.Rational) polynomial {
	return func(x int) rational.Rational {
		y, pow := nr(0), 1
		for _, v := range(coef) { 
			y = y.Add(v.MultiplyByNum(int64(pow)))
			pow *= x
		}
		return y
	}
}

func get_equations(X [][]rational.Rational, y []rational.Rational, N int) [][] rational.Rational {
	s := make([][]rational.Rational, N)
	for i := 0; i < N; i++ {
		s[i] = make([]rational.Rational, N)
		copy(s[i], X[i])
		s[i] = append(s[i][:N], y[i])
	}
	return s
}

func isEqual(n, m rational.Rational) bool {
	return n.GetDenominator() * m.GetNumerator() == n.GetNumerator() * m.GetDenominator()
}

func main() {
	coefficients := []rational.Rational{nr(1), nr(-1), nr(1), nr(-1), nr(1), nr(-1), nr(1), nr(-1), nr(1), nr(-1), nr(1)}
	// coefficients := []rational.Rational{nr(0), nr(0), nr(0), nr(1) }
	N := len(coefficients)

	f := get_polynomial(coefficients)
	y := make([]rational.Rational, N)
	X := make([][]rational.Rational, N)
	for i := 0; i < N; i++ { 
		y[i] = f(i + 1) 
		X[i] = make([]rational.Rational, N)
		for n, j := 1, 0; j < N; j++ {
			X[i][j] = nr(n)
			n *= (i + 1)
		}
	}


	sum := 0
	for i := 0; i < N - 1; i++ {
		equations := get_equations(X, y, i + 1)
		if res, err := gaussian.SolveGaussian(equations, false); err == nil {
			new_coef := make([]rational.Rational, i + 1)
			for j, v := range res { new_coef[j] = v[0] }
			log.Println(new_coef)
			op, fit := get_polynomial(new_coef), 1
			for ;isEqual(op(fit), f(fit)); fit++ { }
			sum += int(op(fit).Float64())
		} else {
			log.Println(err)
		}
	}

	log.Println(sum)
}