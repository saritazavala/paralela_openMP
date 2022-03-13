/*
Sara Zavala 18893
Computacion paralela
*/

#include <unistd.h> 
#include <iostream>
#include <cmath>
#include <fstream>
#include <string> 
#include <omp.h>
#define INFILE "randomNumbers.csv"
#define OUTFILE "Sorted.csv"
using namespace std;


// ----------------------------------------------------
void par_qsort(int *data, int lo, int hi){
 if(lo > hi) return;
 int l = lo;
 int h = hi;
 int p = data[(hi + lo)/2];
    while(l <= h){
        while((data[l] - p) < 0) l++;
            while((data[h] - p) > 0) h--;
                if(l<=h){
                    int tmp = data[l];
                    data[l] = data[h];
                    data[h] = tmp;
                    l++; h--;
                }
            }

 par_qsort(data, lo, h);
 par_qsort(data, l, hi);
}

// ----------------------------------------------------
int main(int argc, char * argv[]) {
 int limChar;
 int threadCount;
 cout<<"Ingrese la cantidad de numeros que desea generar: ";
 cin>>limChar;
    // ----------------------------------------------------
     cout<<"Ingrese la cantidad de threads que desea usar: ";
     cin>>threadCount;
    // ----------------------------------------------------
     int limitArr = limChar;
     cout<<limitArr;

     // ----------------------------------------------------
     int * Array = new int[limitArr];
     int randomNumber;
     omp_set_num_threads(threadCount);


     for (int index = 0; index < limitArr; index++){
        randomNumber = (rand() %35) +1;
        Array[index] = randomNumber;
        }

     ofstream stablishNumbers(INFILE,ios::out);
     if( stablishNumbers.bad() ) {
        cerr<<"Error, no se pudo crear el archivo "<<INFILE<<endl;
        exit(EXIT_FAILURE);
     }

     for(int i=0; i<limitArr;i++){
        stablishNumbers<<Array[i]<<",";
        }


     stablishNumbers.close(); 
    // ----------------------------------------------------

     ifstream leerNumeros;
     leerNumeros.open(INFILE);
    // ----------------------------------------------------
     if( leerNumeros.bad() ) {
        cerr<<"No se ha podido leer el archivo "<<INFILE<<endl;
        exit(EXIT_FAILURE);
        }

     ofstream stablishSort;
     stablishSort.open(OUTFILE);
     // ----------------------------------------------------
     

     if( stablishSort.bad() ) {
        cerr<<"No se pudo crear el archivo "<<OUTFILE<<endl;
        exit(EXIT_FAILURE);
     }
     
     int i = 0;
     string ch;
     while(getline(leerNumeros,ch,',')) {
        int numero = stoi(ch); 
        Array[i] = numero;
        i += 1;

     }
     // ----------------------------------------------------
     cout<<endl;
// ----------------------------------------------------
     #pragma omp parallel
     #pragma omp sections
     {
     #pragma omp section
     par_qsort(Array, 0, limitArr);
     }

     for(int i=0; i<= limitArr; i++){
        stablishSort<<Array[i]<<",";
     }

     stablishSort.close();
     return 0;
}
