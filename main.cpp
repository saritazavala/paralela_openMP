/*
Sara Zavala 18893
Computacion paralela
*/

#include <unistd.h> 
#include <iostream>
#include <cmath>
#include <fstream> 
#include <string> 
#define INFILE "random.csv"
#define OUTFILE "randomSorted.csv"
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
 // ----------------------------------------------------
 cout<<"Ingrese la cantidad de numeros que desea generar: ";
 cin>>limChar;
 // ----------------------------------------------------

 int limitArr = limChar;
 cout<<limitArr;
 int * Array = new int[limitArr];
 int randomNumber;

 }