#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> lista1, lista2, lista3;
    int num;
    
    while (true) {
        cin >> num;
        if (num == 0) break; 
        lista1.push_back(num);  
    }

    while (true) {
        cin >> num;
        if (num == 0) break; 
        lista2.push_back(num); 
    }

    auto it1 = lista1.begin();
    auto it2 = lista2.begin();

    while (it1 != lista1.end() && it2 != lista2.end()) {
        if (*it1 < *it2) {
            lista3.push_back(*it1);
            ++it1;
        } else if (*it2 < *it1) {
            lista3.push_back(*it2);
            ++it2;
        } else {
            
            lista3.push_back(*it1);
            ++it1;
            ++it2;
        }
    }

    
    while (it1 != lista1.end()) {
        lista3.push_back(*it1);
        ++it1;
    }

    while (it2 != lista2.end()) {
        lista3.push_back(*it2);
        ++it2;
    }

    for (int valor : lista3) {
        cout << valor << " ";
    }
    cout << endl;

    return 0;
}