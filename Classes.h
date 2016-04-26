

// Forward Declarations
//class matriz;
//matriz Inverse(const matriz& a);
//double Det(const matriz& a);

static double const parametro = 13.4;

////////////////////////////////////////////////////////
// Class Numerics (data)
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
class Numerics {
    
public:
    int numiter ;
    double numxx ;
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


/********************************************************************/
//					Classe Pheromone
/********************************************************************/
class Pheromone
{
public:
    //    friend class Ants ;     //Acho que não precisa, só se precisasse de coisas private do Ants;
    
    //    Pheromone (Dados);
    
    Matrix Density;
    
    double DiffPhero;
    double EvaporationPhero ;                // Vai ser = 1 na dimensionalização; só por completude.
    //    double * ProductionRatesPhero ;         // Um para cada população!
    double ProductionRatesPhero ;           // Por agora só um pra todos...
    
    Pheromone () {}
    Pheromone (Numerics par) : Density(par) {}
    
};
/********************************************************************/
//					END Classe Pheromone
/********************************************************************/


/********************************************************************/
//					Class Ant
/********************************************************************/
class Ant
{
public:
    
    
    double AntPosX;
    double AntPosY;
    double AntVelX;
    double AntVelY;
    double AntHomeDirX;
    double AntHomeDirY;
    bool IsReturning;
    
    void Walk(Pheromone& current_pheromone);
    
    //  Constructors
    Ant () {
        AntPosX = parametro;
    }
    Ant (const double posX, const double posY){
        AntPosX = posX;
        AntPosY = posY;
        AntVelX = 0.;
        AntVelY = 0.;
        IsReturning = false;
    }
    Ant (Numerics data) {
    }
    //  End Constructors
    
    
    
};
/********************************************************************/
//					END Class Ant
/********************************************************************/
//					Class Ant Functions
/********************************************************************/
//////////////////////////////////////////////////////////////////////
//                  Ant::Walk
//              Here goes each iteration calculation.
//////////////////////////////////////////////////////////////////////

void Ant::Walk(Pheromone& current_pheromone){
    AntPosX = AntPosX + 200.;
    cout << "Estou dentro de Walk:  " << current_pheromone.Density(1,1) <<endl;
    current_pheromone.Density(1,1) = 39.;
}
//////////////////////////////////////////////////////////////////////
//                  END Ant::Walk
//////////////////////////////////////////////////////////////////////


/********************************************************************/
//					END Class Ant Functions
/********************************************************************/




