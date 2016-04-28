# include <fstream>
# include "stdlib.h"
# include <iostream>
# include <cmath>
# include <string>
#include <sstream>
#include <iomanip>  
#include <random>


using namespace std;

static double const numxx = 10.;
static double const numyy = 10.;

//static double const Pi = 3.14159;
static double const Pi =  3.1415926535;
static double const Ln2 = 0.6931471806;

default_random_engine generator;
normal_distribution<double> Normal(0.,1.);      //Normal(0.,1.)
//http://www.cplusplus.com/reference/random/normal_distribution/
// Normal(mean,stddev)
// Usage:
// double number = Normal(generator);
static double const Turn_off_random = 1.*0.1;    //*0.02;
//  ^^^ 0. = No Random!

//	Parameter for Regularizing Function
static double const RegularizingEpsilon = 0.01;


//////////////////////////////////////////////////////
// Ant parameters
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
//  Time scale t_hat em segundos
static double const t_hat_in_seconds = 1.;

//  Space scale X_hat em centimetros
static double const X_hat_in_cm = 1.73;

//  Relaxation time tau em segundos:
static double const tau = .25;         //    0.5

//  Nondimensional relaxation TAU = (t_hat / tau)^(-1).
//  Deve ser o relaxation time nas unidades t_hat.
//  Na equação deve aparecer 1/TAU.
static double const TAU = tau / t_hat_in_seconds;         //

//  Sensing area radius em centimetros
static double const SensingAreaRadius = .4;         //  .5

//  Sensing area radius em X_hat
static double const SENSING_AREA_RADIUS = SensingAreaRadius / X_hat_in_cm;         //

//  Sensing Area Half Angle
static double const SensingAreaHalfAngle = Pi/3.;         //

//  Converter quantidade de feromona numa taxa (velocidade sem espaço). Lambda é 1/(feromona * tempo).
//  A quantidade padrão de feromona dá uma taxa de Lambda / t_hat.
//  Por exemplo, se quando deteta uma quantidade de feromona = 1 ela anda a 2 * X_hat por t_hat, então
//  Lambda seria 2 * (3/2) * (sen theta * ell(em X_hat)^3)^(-1),
//  para que a Velocidade Desejada seja 2. X_hat/t_hat.
//static double const Lambda = .5* (3./2.) *(1./(sin(SensingAreaHalfAngle) * pow(SENSING_AREA_RADIUS,3.)));        //

//  Lambda versao sem sin():
//static double const Lambda = .5* (3./2.) *(1./(1. * pow(SENSING_AREA_RADIUS,3.)));        //

//  Lambda versao só com a media do integral
//static double const Lambda = .5* (3./2.) *(1./(SensingAreaHalfAngle * pow(SENSING_AREA_RADIUS,3.)));        //

//	With Weber's Law, Lambda may be ~ 1 ??
static double const Lambda = 1.;         //10./SENSING_AREA_RADIUS;????

//////////////////////////////////////////////////////
// End Ant parameters
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////

// tempo final
//static double const TFINAL = 0.1;
static double const delta_t = 0.05;   //     0.005


////////////////////////////
//  Definição do  Domínio
////////////////////////////
// extremo inferior do intervalo em x (cm)
static double const x_1_cm = -25.;

// extremo superior do intervalo em x (cm)
static double const x_2_cm = 25.;

// extremo inferior do intervalo em y (cm)
static double const y_1_cm =  -50.;

// extremo superior do intervalo em y (cm)
static double const y_2_cm = 50.;

// extremo inferior do intervalo em x
static double const x_1 = x_1_cm / X_hat_in_cm;

// extremo superior do intervalo em x
static double const x_2 = x_2_cm / X_hat_in_cm;

// extremo inferior do intervalo em y
static double const y_1 = y_1_cm / X_hat_in_cm;

// extremo superior do intervalo em y
static double const y_2 = y_2_cm / X_hat_in_cm;

////////////////////////////
// End Definição do  Domínio
////////////////////////////

static double const delta_x = (x_2-x_1)/numxx;;
static double const delta_y = (y_2-y_1)/numyy;;

////////////////////////////
// Parametro temporário para a pheromone
////////////////////////////
static double const PheroNarrow = 1.;
static double const PheroHigh = 1.;
////////////////////////////
// End Parametro temporário para a pheromone
////////////////////////////

////////////////////////////
// Parametro Só para os plots não ficarem
//  com um risco do lado ao outro
//  quando muda de lado por periodicidade
////////////////////////////
int ChangedSide = 0;




#include "Classes.h"
//#include "matriz.h"
//#include "Matrix.h"



int main (void){
    
    static double const parametro2 = 532.4;
    
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
    
    
    Ant::Pheromone.Print();
    Ant formiga3;
    cout << "LALALA:  " << Ant::Pheromone(1,1) <<endl;
    formiga3.Walk();
    cout << "LALALA 2:  " << Ant::Pheromone(1,1) <<endl;
    cout << "LALALA 4:" << formiga3.PheromoneConcentration() << endl;
    
    //////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////

    int NN = 3;
    
    Ant * Pop;
    Pop = new Ant[NN];
//    cout << "Agora:  " << Pop[1].AntDepositedPhero(1,1) <<endl;
    cout << "Agora:  " << Pop[1].AntPosY <<endl;
    Pop[1].Walk();
    cout << "LALALA 3:  " << Ant::Pheromone(1,1) <<endl;
    
    
    return 0;
}





    
    
    
    
    
    
    
    
    




