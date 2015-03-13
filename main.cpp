#include "NodoArbolBinario.h"
#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <list>          // std::list
using namespace std;

//Devuelve la suma de todos los numeros del arbol con la raiz dada.
int suma(NodoArbolBinario* raiz)
{
    if(raiz==NULL)return 0; //Verifica la raiz, en caso de ser nula, retorna 0
    return raiz->num + suma(raiz->hijo_der) + suma(raiz->hijo_izq); //se retorna la suma de los hijos directamente
}

//Devuelve la cantidad de nodos que tiene el arbol con la raiz dada.
int cantidadNodos(NodoArbolBinario* raiz)
{
    if(raiz==NULL)return 0; //Verifica la raiz, en caso de ser nula, retorna 0
    if(raiz->hijo_der == NULL && raiz->hijo_izq==NULL) // se verifica si los hijos de ambos lados no sean nulos, caso contrario, se retorna 1
    return 1;
    return (cantidadNodos(raiz->hijo_der)+cantidadNodos(raiz->hijo_izq))+1; // se retorna la cantidad de hijos directamente
}

//Devuelve el promedio de los numeros que tiene el arbol con la raiz dada.
int promedio(NodoArbolBinario* raiz)
{
    int capsule1 = 1; //inicializacion de la variable 
    capsule1 = raiz->num + suma(raiz->hijo_der) + suma(raiz->hijo_izq);// se define a capsule 1 como la suma de todas los hijos
    int capsule2 = 0; //inicializacion de capsule 2
    capsule2 = (cantidadNodos(raiz->hijo_der)+cantidadNodos(raiz->hijo_izq))+1; // se define capsule 2 como la cantidad de hijos existente
    int result = 0; //inicializacion de variable resultado
    result = capsule1 / capsule2; //se divide capsula 1 entre capsula 2 para obtener el promedio
    return result; // se retorna result como resultado
}

//Devuelve la cantidad de pasos que tiene que dar el algoritmo para llegar a un numero dado.
//Ejemplo: http://www.comp.nus.edu.sg/~stevenha/visualization/bst.html
//Para llegar al nodo 7 se ocupan 3 pasos (15,6,7)
//Para llegar al nodo 5 se ocupan 4 pasos (15,6,4,5)
//Para llegar al nodo 15 se ocupa 1 paso (15)
int cuantosPasos(NodoArbolBinario* raiz,int num)
{
    int counter = 0;
    if(raiz==NULL)return 1; //Verifica la raiz, en caso de ser nula, retorna 1
    if(raiz->num == num)return 1; //Verifica la raiz, en caso de ser nula, retorna 0
    if(num>raiz->num){counter +=cuantosPasos(raiz->hijo_der,num)+1;} //llamada recursiva donde se le suma al contador los pasos + 1
    if(num<raiz->num){counter +=cuantosPasos(raiz->hijo_izq,num)+1;} //llamada recursiva donde se le suma al contador los pasos + 1
    return counter; // se returna el ontador
}

//Devuelve la cantidad de hojas que tiene el arbol con la raiz dada
int sumaHojas(NodoArbolBinario* raiz)
{
    if(raiz==NULL)return 0; //Verifica la raiz, en caso de ser nula, retorna 0
    if((raiz->hijo_der==NULL) && (raiz->hijo_izq==NULL))return 1; //Verifica los hijos, en caso de ser nulos, retorna 1
    return sumaHojas(raiz->hijo_der)+sumaHojas(raiz->hijo_izq); //se hace la llamada recursiva con la suma de las hojas
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 1;
}
