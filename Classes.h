


//static double const parametro = 13.4;
double  parametro = 13.4;




////////////////////////////////////////////////////////
// Class Numerics (data)
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
class Numerics {
    
public:
    int numiter ;
    double numxx ;  //sdsfs
    double numyy ;
    string Comm;
    
    Numerics (){
        cout << "// Comments:" << endl;
        getline(cin, Comm, '\n');               // Nice... de http://www.cprogramming.com/tutorial/string.html
        cout << "// Number of x intervals:" << endl;
        cin >> numxx ;
        cout << "// Number of y intervals:" << endl;
        cin >> numyy ;
        cout << "// Number of time iterations:" << endl;
        cin >> numiter ;
        cin.ignore() ;
        // Because C++!! ver http://stackoverflow.com/questions/12691316/getline-does-not-work-if-used-after-some-inputs
        // … pq o ultimo cin deixa l· um \n que se n„o fizer isto È lido pelo prÛximo getline.
        // Sem isto, sÛ lÍ Comm da 1a vez que È chamado durante a execuÁ„o. Sigh...
    }
    
};
////////////////////////////////////////////////////////
// END Class Numerics (data)
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////


#include "Matrix.h"
class Ant;

/********************************************************************/
//					Classe Pheromone
/********************************************************************/
//class Pheromone
//{
//public:
//    //    friend class Ants ;     //Acho que não precisa, só se precisasse de coisas private do Ants;
//    
//    //    Pheromone (Dados);
//    
//    Matrix Density;
//    
//    double DiffPhero;
//    double EvaporationPhero ;                // Vai ser = 1 na dimensionalização; só por completude.
//    //    double * ProductionRatesPhero ;         // Um para cada população!
//    double ProductionRatesPhero ;           // Por agora só um pra todos...
//    
//    Pheromone () {}
//    Pheromone (Numerics par) : Density(par) {}
//    
//    void Update(Matrix& mat);      // This function will only add the values in mat to the
//                                            //      values of Density.
//    
//};
//void Pheromone::Update(Matrix& mat){
//    Pheromone::Density(1,1) = 53.6;
//}
/********************************************************************/
//					END Classe Pheromone
/********************************************************************/


/********************************************************************/
//					Class Ant
/********************************************************************/
class Ant
{
public:
    
    static Matrix Pheromone;
                        // cf. http://www.tutorialspoint.com/cplusplus/cpp_static_members.htm
                        //  This way (a static Matrix) I don't need the Pheromone class.
                        //  Bit dx, dy, etc must now be defined in the beggining of the main file.
    
    double AntPosX;
    double AntPosY;
    double AntVelX;
    double AntVelY;
    double AntHomeDirX;
    double AntHomeDirY;
    bool IsReturning;
    Matrix AntDepositedPhero;
    
    void Walk();
    
    //  Constructors
    Ant () {
        AntPosX = parametro;
        AntPosY = 456.7;
    }
    Ant (const double posX, const double posY){
        AntPosX = posX;
        AntPosY = posY;
        AntVelX = 0.;
        AntVelY = 0.;
        IsReturning = false;
    }
    Ant (Numerics data) : AntDepositedPhero(data) {
        AntPosX = 0.;
        AntPosY = 0.;
        AntVelX = 0.;
        AntVelY = 0.;
        IsReturning = false;
        

    }
    //  End Constructors
    
};
Matrix Ant::Pheromone = Zeros(numxx,numyy);

/********************************************************************/
//					END Class Ant
/********************************************************************/
//					Class Ant Functions
/********************************************************************/
//////////////////////////////////////////////////////////////////////
//                  Ant::Walk
//              Here goes each iteration calculation.
//////////////////////////////////////////////////////////////////////

void Ant::Walk(){
    AntPosX = AntPosX + 200.;
    cout << "Estou dentro de Walk:  " << Pheromone(1,1) <<endl; // Read Pheromone ok
    Pheromone(1,1) = 39.;                                       // Change Pheromone ok
}
//////////////////////////////////////////////////////////////////////
//                  END Ant::Walk
//////////////////////////////////////////////////////////////////////


/********************************************************************/
//					END Class Ant Functions
/********************************************************************/




