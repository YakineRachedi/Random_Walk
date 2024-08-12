#include <iostream>
#include <ctime>
#include <fstream>
#include "random_walk.hpp"
using namespace std;
using MT = mt19937;

int main(){
    MT G(time(nullptr));
    RandomWalk_with_min X(0,0.5);
    const int realisations = 10000;
    ofstream F1("RW.dat");
    ofstream F2("RWMin.dat");
    for(int i = 0; i < realisations; i++){
        X.update(G);
        F1 << X.time() <<"\t" << X.val() <<"\n";
        F2 << X.time() << "\t" << X.minimum() << "\n";
    }
    F1.close();
    F2.close();



    return 0;
}