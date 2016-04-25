

// Forward Declarations
//class my_matrix;
//my_matrix Inverse(const my_matrix& a);
//double Det(const my_matrix& a);



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


#include "matriz.h"


/********************************************************************/
//					Classe Pheromone
/********************************************************************/
class Pheromone
{
public:
    //    friend class Ants ;     //Acho que não precisa, só se precisasse de coisas private do Ants;
    
    //    Pheromone (Dados);
    
    my_matrix PheromoneDensity;
    
    double DiffPhero;
    double EvaporationPhero ;                // Vai ser = 1 na dimensionalização; só por completude.
    //    double * ProductionRatesPhero ;         // Um para cada população!
    double ProductionRatesPhero ;           // Por agora só um pra todos...
    
    Pheromone () {}
    Pheromone (Numerics par) : PheromoneDensity(par) {}
    
};



