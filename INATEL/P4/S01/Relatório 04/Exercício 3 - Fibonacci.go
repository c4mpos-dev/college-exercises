package main

import (
	"fmt"
)

func fibonacci(n int) []int {
	seq := []int{}

	a, b := 0, 1
	for i := 0; i < n; i++ {
		seq = append(seq, a)
		a, b = b, a+b
	}

	return seq
}

func main() {
	var n int
	fmt.Print("Digite quantos números da sequência de Fibonacci você deseja: ")
	fmt.Scan(&n)

	sequencia := fibonacci(n)

	fmt.Println("Sequência de Fibonacci:")
	for _, valor := range sequencia {
		fmt.Print(valor, " ")
	}
	fmt.Println()
}