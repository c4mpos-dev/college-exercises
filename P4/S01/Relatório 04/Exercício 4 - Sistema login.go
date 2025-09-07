package main

import (
	"fmt"
)

func verificarLogin(usuario, senha string) bool {
	if usuario == "senha" && senha == "admin" {
		return true
	}

	return false
}

func main() {
	for {
		var usuario, senha string

		fmt.Print("Digite o usuário: ")
		fmt.Scan(&usuario)

		fmt.Print("Digite a senha: ")
		fmt.Scan(&senha)

		if verificarLogin(usuario, senha) {
			fmt.Println("Login bem-sucedido!")
			break
		} else {
			fmt.Println("Usuário ou senha incorretos. Tente novamente.")
		}
	}
}