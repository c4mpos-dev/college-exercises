#include<iostream>
using namespace std;

// Nota: 9,5 / 10
// -0,5pts por utilizar --> break;

int sequencial(string vetor[], int tamanho, string x){
    bool achou = false; // var aux p/ busca
    int i = 0; // contador
    while (achou == false && i < tamanho){	
        if (vetor[i] == x)
            achou = true;	
            i++;
    }
    if (achou == true)
        return (i - 1);
    else
        return -1;
}

struct item{
    string nome; // nome do filme
    float nota; // nota do filme no IMDb
};

int main(){
    item filme[20];
    string nome, nomeBuscado, nomesFilmes[20];
    int i = 0;
    
    while(true){
        getline(cin, nome);
        
        if (nome == "fim"){
            break;
        }
        else{
            filme[i].nome = nome;
            cin >> filme[i].nota;
            cin.ignore();
        }
        
        i++;
    }
    
    getline(cin, nomeBuscado);
    
    for (int j = 0; j < i; j++)
        nomesFilmes[j] = filme[j].nome;
        
    int search = sequencial(nomesFilmes, i, nomeBuscado);
    
    if (search != -1){
        for (int k = 0; k < i; k++) {
            if (filme[k].nome == nomesFilmes[search]) {
                cout << "IMDb: " << filme[k].nota << endl;  
                break;
            }
        }
    }
    else{
        cout << "Filme nao encontrado" << endl;
    }
    
    return 0;
}