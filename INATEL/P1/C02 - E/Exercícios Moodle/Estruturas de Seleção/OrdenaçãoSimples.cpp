#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle Ordenação Simples
	
    int a, b, c;
    int pos1, pos2, pos3;

    cin >> a >> b >> c;

    // A maior de todos
    if (a >= b && a >= c) {
        pos3 = a;
        if (b >= c) {
            pos2 = b;
            pos1 = c;
        }
        else {
            pos2 = c;
            pos1 = b;
        }
    }
    // A no meio 1
    else if (a >= b && a <= c) {
        pos1 = b;
        pos2 = a;
        pos3 = c;
    }
    // A no meio 2
    else if (a <= b && a >= c) {
        pos1 = c;
        pos2 = a;
        pos3 = b;
    }
    // A menor de todos
    else {
        pos1 = a;
        if (b >= c) {
            pos3 = b;
            pos2 = c;
        }
        else {
            pos3 = c;
            pos2 = b;
        }
    }

    cout << pos1 << endl << pos2 << endl << pos3 << endl << endl;
    cout << a << endl << b << endl << c << endl;

    return 0;

}