#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>


using namespace std;

struct Produto {
	string nomeDoProduto;
	double pesoDoProduto;
	double tamanhoDoProduto;
	int fragilidadeDoProduto;
};

struct Pessoa {
	string nome;
	string estiloMusical;
	int idade;
	int tipoDeCarro;
	int tempArCondicionado;
};


double transporteDeProdutos() {
	Produto carga;
	double distancia;
	double pesoMultiplier = 0.5;
	double tamanhoMultiplier = 0.7;
	double distanciaMultiplier = 0.8;
	double valorTotal;

	cout << "Insira o nome do produto: ";
	cin.ignore();
	getline(cin, carga.nomeDoProduto);

	do {
		cout << "Insira o peso do produto (ate 100kg): ";
		cin >> carga.pesoDoProduto;
		if (carga.pesoDoProduto <= 0) {
			cout << "O peso do produto nao pode ser menor ou igual a 0"<< endl;
		}
		else if (carga.pesoDoProduto > 100) {
			cout << "Produto nao pode ser maior que 100kg" << endl;
		}
	} while (carga.pesoDoProduto <= 0 || carga.pesoDoProduto > 100);

	do {
		cout << "Insira o tamanho do produto (ate 2 metros): ";
		cin >> carga.tamanhoDoProduto;

		if (carga.tamanhoDoProduto <= 0) {
			cout << "O produto nao pode ter um tamanho menor ou igual a 0m" << endl;
		}
		else if (carga.tamanhoDoProduto > 2) {
			cout << "O produto nao pode ter um tamanho maior que 2m" << endl;
		}
	} while (carga.tamanhoDoProduto <= 0 || carga.tamanhoDoProduto > 2);

	do {
		cout << "Insira a fragilidade do produto de 1 a 3, sendo 3 mais fragil e 1 menos fragil: ";
		cin >> carga.fragilidadeDoProduto;

		if (carga.fragilidadeDoProduto < 1 || carga.fragilidadeDoProduto > 3) {
			cout << "Insira uma fragilidade valida!" << endl;
		}

	} while (carga.fragilidadeDoProduto < 1 || carga.fragilidadeDoProduto > 3);

	do {
		cout << "Insira a distancia que o motorista ira percorrer (de 1km ate 100km): ";
		cin >> distancia;

		if (distancia < 1) {
			cout << "A distancia deve ser maior que 1km" << endl;
		}
		else if (distancia > 100) {
			cout << "A distancia deve ser menor que 100km" << endl;
		}

	} while (distancia > 100 || distancia < 1);

	valorTotal = ((carga.pesoDoProduto * pesoMultiplier) + (carga.tamanhoDoProduto * tamanhoMultiplier) + (distancia * distanciaMultiplier)) * carga.fragilidadeDoProduto;
	cout << "O transporte do produto " << carga.nomeDoProduto << " sera de R$ " << fixed << setprecision(2) << valorTotal << endl;
	return valorTotal;
}

double transporteDePessoas() {
	Pessoa passageiro;
	double distancia;
	double veiculoMultiplier;
	double valorTotal;

	cout << "Digite o nome do passageiro: ";
	cin.ignore();
	getline(cin, passageiro.nome);

	do {
		cout << "Insira a idade do passageiro (passageiro deve ser maior que 18 anos): ";
		cin >> passageiro.idade;

		if (passageiro.idade < 18) {
			cout << "Passageiro deve ser maior de 18 anos!" << endl;
		}
	} while (passageiro.idade < 18);

	do {
		cout << "Digite o tipo de carro que deseja: (1 - Combustao 2 - Eletrico) ";
		cin >> passageiro.tipoDeCarro;

		if (passageiro.tipoDeCarro != 1 && passageiro.tipoDeCarro != 2) {
			cout << "Tipo de veiculo invalido.";
		}

	} while (passageiro.tipoDeCarro != 1 && passageiro.tipoDeCarro != 2);

	if (passageiro.tipoDeCarro == 1) {
		veiculoMultiplier = 2.7;
	}
	else if (passageiro.tipoDeCarro == 2) {
		veiculoMultiplier = 3.4;
	}

	do {
		cout << "Digite a temperatura desejada do ar-condicionado (de 18 a 24): ";
		cin >> passageiro.tempArCondicionado;

		if (passageiro.tempArCondicionado < 18 && passageiro.tempArCondicionado > 24) {
			cout << "Temperatura invalida." << endl;
		}

	} while (passageiro.tempArCondicionado < 18 && passageiro.tempArCondicionado > 24);

	cout << "Digite o genero musical desejado: ";
	cin.ignore();
	getline(cin, passageiro.estiloMusical);
	

	do {
		cout << "Digite a distancia percorrida (de 1km a 300km): ";
		cin >> distancia;

		if (distancia < 1) {
			cout << "Distancia deve ser maior que 1km" << endl;
		}
		else if (distancia > 300) {
			cout << "Distancia deve ser menor que 300km" << endl;
		}
	} while (distancia < 1 || distancia > 300);

	valorTotal = distancia * (veiculoMultiplier - (veiculoMultiplier / 100));
	
	cout << "O transporte de " << passageiro.nome << " ouvindo musicas do genero " << passageiro.estiloMusical << " com a temperatura do ar-condicionado configurada para " << passageiro.tempArCondicionado << " sera de R$ " << fixed << setprecision(2) << valorTotal << endl;

	return valorTotal;
}

void descontoPorCupom(double valorTotal, string cupom) {
	string cupons[3] = { "viagem100", "araraazul", "aniversario" };
	if (cupom == "viagem100" || cupom == "araraazul" || cupom == "aniversario") {
		cout << "Cupom de desconto aceito!" << endl;
		cout << "Valor sem desconto: R$ " << valorTotal << endl;
		cout << "Valor com desconto aplicado: R$ " << fixed << setprecision(2) << valorTotal - (valorTotal * 0.1) << endl;
	} else {
		cout << "Cupom nao encontrado." << endl;
	};
}

void metodoDePagamento() {
	int metodoDePagamento;

	do {
		cout << "Digite o metodo de pagamento: \n 1 - Cartao credito \n 2 - Cartao debito \n 3 - Dinheiro \n 4 - Criptomoeda  \n";
		cin >> metodoDePagamento;

		if (metodoDePagamento != 1 && metodoDePagamento != 2 && metodoDePagamento != 3 && metodoDePagamento != 4) {
			cout << "Selecione um metodo de pagamento valido" << endl;
		}

	} while (metodoDePagamento != 1 && metodoDePagamento != 2 && metodoDePagamento != 3 && metodoDePagamento != 4);

	cout << "Processando pagamento..." << endl;
	
	Sleep(5000);
	cout << "Pagamento aprovado!" << endl;
	cout << "Agradecemos a preferencia, tenha uma boa viagem!" << endl;
}

int main()
{
	int tipoDeServico;
	int cupomDeDesconto;
	double valorTotal;

	cout << "Bem vindo ao aplicativo E-Route!" << endl;

	do {
		cout << "Defina o tipo do servico que voce deseja:" << endl;
		cout << "1 - Transporte de produtos" << endl;
		cout << "2 - Transporte de pessoas" << endl;
		cin >> tipoDeServico;
		
		if (tipoDeServico != 1 && tipoDeServico != 2) {
			cout << "Por favor, insira um serviço valido" << endl;
		}
	} while (tipoDeServico != 1 && tipoDeServico != 2);

	if (tipoDeServico == 1) {
		valorTotal = transporteDeProdutos();
		cout << "Deseja aplicar cupom de desconto? (1 - sim, 2 - nao) ";
		cin >> cupomDeDesconto;
		if (cupomDeDesconto == 1) {
			string cupom;
			cin.ignore();
			cout << "Insira o cupom: ";
			getline(cin, cupom);
			descontoPorCupom(valorTotal, cupom);
		}
	}
	else if (tipoDeServico == 2) {
		valorTotal = transporteDePessoas();
		cout << "Deseja aplicar cupom de desconto? (1 - sim, 2 - nao)";
		cin >> cupomDeDesconto;
		if (cupomDeDesconto == 1) {
			string cupom;
			cin.ignore();
			cout << "Insira o cupom: ";
			getline(cin, cupom);
			descontoPorCupom(valorTotal, cupom);
		}
	}

	metodoDePagamento();
}


