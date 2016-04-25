# include <fstream>
# include "stdlib.h"
# include <iostream>
# include <cmath>
# include <string>
#include <sstream>
#include <iomanip>  
#include <random>

using namespace std;

#include "Classes.h"
//#include "matriz.h"



int main (void){
    
    Numerics Teste;
    my_matrix MT(4,4);
    my_matrix NT(Teste);
    MT.print();
    NT.print();
    printf("hello\n");
    
    Pheromone fero(Teste);
    cout << fero.PheromoneDensity.dim1 <<endl;
    
    return 0;
}





    
    
    
    
    
    
    
    
    




