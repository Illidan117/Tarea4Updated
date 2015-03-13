#include "NodoArbolBinario.h"
#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <list>          // std::list
using namespace std;

//Devuelve la suma de todos los numeros del arbol con la raiz dada.
int suma(NodoArbolBinario* raiz)
{
    if(raiz==NULL)return 0;
    return raiz->num + suma(raiz->hijo_der) + suma(raiz->hijo_izq);
}

//Devuelve la cantidad de nodos que tiene el arbol con la raiz dada.
int cantidadNodos(NodoArbolBinario* raiz)
{
    if(raiz==NULL)return 0;
    if(raiz->hijo_der == NULL && raiz->hijo_izq==NULL)
    return 1;
    return (cantidadNodos(raiz->hijo_der)+cantidadNodos(raiz->hijo_izq))+1;
}

//Devuelve el promedio de los numeros que tiene el arbol con la raiz dada.
int promedio(NodoArbolBinario* raiz)
{
    int capsule1 = 0;
    capsule1 = raiz->num + suma(raiz->hijo_der) + suma(raiz->hijo_izq);
    int capsule2 = 0;
    capsule2 = (cantidadNodos(raiz->hijo_der)+cantidadNodos(raiz->hijo_izq))+1;
    int result = 0;
    result = capsule1 / capsule2;
    return result;
}

//Devuelve la cantidad de pasos que tiene que dar el algoritmo para llegar a un numero dado.
//Ejemplo: http://www.comp.nus.edu.sg/~stevenha/visualization/bst.html
//Para llegar al nodo 7 se ocupan 3 pasos (15,6,7)
//Para llegar al nodo 5 se ocupan 4 pasos (15,6,4,5)
//Para llegar al nodo 15 se ocupa 1 paso (15)
int cuantosPasos(NodoArbolBinario* raiz,int num)
{
    return -1;
}

//Devuelve la cantidad de hojas que tiene el arbol con la raiz dada
int sumaHojas(NodoArbolBinario* raiz)
{
    if(raiz==NULL)return 0;
    if((raiz->hijo_der==NULL) && (raiz->hijo_izq==NULL))return 1;
    return sumaHojas(raiz->hijo_der)+sumaHojas(raiz->hijo_izq);
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 1;
}