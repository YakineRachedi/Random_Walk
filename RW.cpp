#include <iostream>
#include <ctime>
#include <fstream>
#include "random_walk.hpp"
using namespace std;
using MT = mt19937;

int main(){
    MT G(time(nullptr));
    RandomWalk m(0,0.5);
    const int realisations = 10000;
    ofstream F1("RW.dat");
    for(int i = 0; i < realisations; i++){
        m.update(G);
        F1 << m.val() << "\n";
    }
    F1.close();



    return 0;
}