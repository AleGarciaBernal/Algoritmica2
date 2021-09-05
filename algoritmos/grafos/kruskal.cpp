#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
// Variables
#define MAX_N 10000    // Maximo numero de vertices o nodos, depende al problema

using namespace std; 

// parent y rango sirven para el union find 
int parent[MAX_N];
int rango[MAX_N];

int n, m; // n numero de nodos y m numero de aristas 

void init() { // inicializamos, todos nuestros vertices vacios y apuntandose a si mismos
    for(int i=0;  i<= MAX_N; i++) {   // puede que aqui sea solo menor que
        parent[i] = i;
        rango[i] = 0;
    }
}

int find(int x) { //solo nos dice cual es el padre de X nodo de nivel 0
    if(x == parent[x]) {
        return x;
    }
    else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

bool sameComponent(int nodeA,int nodeB) { //nos dice si forman un ciclo, tiene que ser diferente
    return find(nodeA) == find(nodeB);
}

void unionRango(int x,int y) { // unir nodos, y que este balanceado
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
    } else {
        parent[xRaiz] = yRaiz;
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}

struct Arista{ // la matriz de inicio, fin y el peso de la arista que los une
    int origen;
    int destino; 
    double peso; 

    Arista(){} // constructor
    // sobrecarga del operador < para ordenar las aristas
    // modififca a la funcion sort 
    
    /*bool operator<(const Arista &a) const {
        if(peso == a.peso) {
            return origen < a.origen;
        } else {
            return peso < a.peso;
        }
    }*/

//orden apartir del peso

    bool operator<(const Arista &a) const {
       return peso<a.peso;// aqui le decimos en que se basa para ordenar
    }    

}aristas[MAX_N]; //array de tipo aristas, con 3 elementos

Arista MST[MAX_N]; // n-1 aristas 

int numAristasArbol;

double kruskal(int nroNodos, int nroAristas) {
    
    int origen, destino;
    double peso;

    double total = 0; // total del arbol de expansión minimo 

    numAristasArbol = 0; // contar el numero de aristas 

    init(); // Iniciar el union Find 

    sort(aristas,aristas + nroAristas); // ordena las aristas, de aristas hasta el total de aristas
    // sort utiliza el operador < 
    // sort(array, array+n)
    // array = [a,b,c,d,e]
    // n = 5
    // sort(array, array+5)

    for (int i = 0; i < nroAristas; i++)
    {
        origen = aristas[i].origen;
        destino = aristas[i].destino;
        peso = aristas[i].peso;

        if(!sameComponent(origen,destino)) { // estos 2 dos nodos forman un ciclo ?
            total += peso; 
            MST[numAristasArbol] = aristas[i]; // Guardamos la arista agregada
            unionRango(origen,destino);  // unimos los nodos
            
            numAristasArbol++; // incrementados la posicion para la futura arista
            
        }
    }
    return total;
}

int main(){
    input;

    while(scanf("%d %d",&n,&m) != EOF) {
        for(int i=0; i<m; i++) {
            scanf("%d %d %lf",&aristas[i].origen,&aristas[i].destino,&aristas[i].peso);
        }
        printf("%.2lf\n",kruskal(n,m));
        // Imprimo el arbol de expasion minimo
        for(int i = 0 ;i <numAristasArbol;i++) { // imprimir arbol
            cout<<MST[i].origen<<" "<<MST[i].destino<<" "<<MST[i].peso<<endl;
        }
    }

    return 0;
}