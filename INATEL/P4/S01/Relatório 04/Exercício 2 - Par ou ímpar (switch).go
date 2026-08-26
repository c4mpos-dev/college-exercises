package main

import (
	"fmt"
)

func main() {
	var num int
	fmt.Print("Digite um número: ")
	fmt.Scan(&num)

	switch num % 2 {
		case 0:
			fmt.Println("O número é par.")
		default:
			fmt.Println("O número é ímpar.")
	}
}