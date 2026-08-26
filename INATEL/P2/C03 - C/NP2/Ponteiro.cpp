#include<iostream>
using namespace std;

int main() {
    int N, alunosEmRisco = 0;
    cin >> N;

    string *v = new string[N];

    for (int i = 0; i < N; i++)
        cin >> v[i];

    string *p = v;

    for (int i = 0; i < N; i++) {
        if (*p == "E" || *p == "D") alunosEmRisco++;
        p++;
    }

    cout << alunosEmRisco << " alunos em risco de reprovacao" << endl;

    return 0;
}

// Como os conceitos são dados por uma única letra, é mais adequado usar char ao invés de string (-5 pts)