#include<iostream>

using namespace std;

int main(){

    int nVideos = 0, nViews[999], nMaior = 0, nMenor = 0;
    
    do {
        cin >> nVideos;
    }while(nVideos < 0 || nVideos > 1000);

    for (int i = 0; i < nVideos; i++)
        cin >> nViews[i];

    for (int i = 0; i < nVideos; i++){
        if (nViews[i] > 10000000)
            nMaior++;
        else if  (nViews[i] < 10000000)
            nMenor++;

    }
        
    cout << nMaior << " video(s) com mais de 10M views" << endl;
    cout << nMenor << " video(s) com menos de 10M views" << endl;

}   