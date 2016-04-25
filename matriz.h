
////////////////////////////////////////////////////////
//  Class my_matrix
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
class my_matrix {
public:
    int lines,cols;
    double * elementos;
    
    
    my_matrix (){}
    my_matrix (int m,int n)
    {
        lines=m;
        cols=n;
        elementos=new double[m*n];
        for (int i=0; i< lines ; i++) {
            for (int j=0; j<cols; j++) {
                elementos[i*cols+j] = 0.;
            }
        }
    }
    my_matrix (Numerics& data)
    {
        lines=data.numxx;
        cols=data.numyy;
        elementos=new double[lines*cols];
        for (int i=0; i< lines ; i++) {
            for (int j=0; j<cols; j++) {
                elementos[i*cols+j] = 3.;
            }
        }
    }
    //    ~my_matrix()
    //    {
    //        delete[] elementos;
    //    }
    
    
    double &operator() (int i,int j){
        if(i>=lines){
            cout << "erro x" << endl;
            exit(1);}
        if(j>=cols){
            cout << "erro y" << endl;
            exit(1);}
        
        return elementos[i*cols+j];
    }
    
    
    
    
    void print (){
        int i,j;
        for(i=0;i<lines;i++)
            for(j=0;j<cols;j++){
                cout << operator()(i,j) << " ";
                if(j==cols-1)
                    cout << endl;
            }
    }
    
    
    
    
    
};

// Ver http://condor.depaul.edu/ntomuro/courses/262/notes/lecture3.html
my_matrix operator+(const my_matrix &M1, const my_matrix &M2)
{
    my_matrix soma (M1.lines, M1.cols);
    for (int i=0; i< soma.lines ; i++) {
        for (int j=0; j<soma.cols; j++) {
            soma.elementos[i*M1.cols+j] = M1.elementos[i*M1.cols+j] + M2.elementos[i*M1.cols+j];
        }
    }
    return soma;
}
my_matrix operator-(const my_matrix &M1, const my_matrix &M2)
{
    my_matrix soma (M1.lines, M1.cols);
    for (int i=0; i< soma.lines ; i++) {
        for (int j=0; j<soma.cols; j++) {
            soma.elementos[i*M1.cols+j] = M1.elementos[i*M1.cols+j] - M2.elementos[i*M1.cols+j];
        }
    }
    return soma;
}
my_matrix operator*(const my_matrix &M1, const double C)
{
    my_matrix prod (M1.lines, M1.cols);
    prod = M1;
    
    for (int i=0; i< prod.lines ; i++) {
        for (int j=0; j<prod.cols; j++) {
            prod.elementos[i*M1.cols+j] *= C ;
        }
    }
    return prod;
}
my_matrix operator*(const my_matrix &M1, const my_matrix &M2)
{
    my_matrix prod (M1.lines, M1.cols);
    double aux = 0.;
    for (int i=0; i< prod.lines ; i++) {
        for (int j=0; j<prod.cols; j++) {
            for (int k=0; k<prod.cols; k++) {
                aux += M1.elementos[i*M1.cols+k] * M2.elementos[k*M1.cols+j];
            }
            prod.elementos[i*M1.cols+j] = aux;
            aux = 0.;
        }
    }
    return prod;
}
////////////////////////////////////////////////////////
// END Class my_matrix
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////



