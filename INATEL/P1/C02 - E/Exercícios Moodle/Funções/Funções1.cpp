#include<iostream>
#include<cmath>

using namespace std;

int calc_a(int x){
    return ((2 * pow(x, 2)) + (3 * x)) - 1;
}

int calc_b(int x){
    return pow(x, 3);
}

int calc_c(int y){
    return pow(y , 3);
}

int main()
{
    int a,b,c,x,y;

    cin >> x >> y;

    a = calc_a(x);
    cout << "a = " << a << endl;
    b = calc_b(x);
    cout << "b = " << b << endl;
    c = calc_c(y);
    cout << "c = " << c << endl;

    return 0;
}