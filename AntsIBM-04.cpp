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
//#include "Matrix.h"



int main (void){
    
    Numerics Teste;
//    matriz MT(4,4);
//    matriz NT(Teste);
//    MT.print();
//    NT.print();
    printf("hello\n");
    
    Matrix T2(5,5);
    T2(1,1) = 3.;
    Matrix T3(5,5);
    Matrix T4(Teste);
    T3 = T2;
    T4.Print();
    
    
    cout << "Here: "<<T3(1,1) <<endl;
    
    Pheromone fero(Teste);
    cout << fero.Density.rows <<endl;
    
    Ant formiga1(Teste);
    formiga1.IsReturning = true;
    cout << "HEY:  " << formiga1.IsReturning <<endl;
    Ant formiga2;
    cout << "HEY2:  " << formiga2.AntPosX <<endl;
    formiga2.Walk(fero);
    cout << "HEY3:  " << formiga2.AntPosX <<endl;
    cout << "HEY4:  " << fero.Density(1,1) <<endl;
    cout << "HEY5:  " << parametro <<endl;  //  Can use parametro because it is defined in Classes.h
    
    cout << "HEY6:  " << formiga1.AntDepositedPhero(1,1) << endl;
    fero.Update(formiga1.AntDepositedPhero);
    formiga1.AntDepositedPhero.Print();
    fero.Density.Print();
    
    
    
    return 0;
}





    
    
    
    
    
    
    
    
    




