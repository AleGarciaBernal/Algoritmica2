#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int[]numbers={1,2,3,4,5,6,7,8};

struct node{
    int minimo;
}segmentTree[10000000];

void init (int inicio, int fin, int nodoActual){
    if(inicio=fin){
        segmentTree[nodoActual].minimo=numbers[inicio];
    }else{
        int medio=(inicio+fin)/2;
        int hijoIzq=2*nodoActual+1;
        int hijoDer=2*nodoActual+2;

        //ir por izqu
        init(inicio,medio,hijoIzq); 
        //ir por derecha
        init(medio+1, fin, hijoDer);

        //Actualizar el nodo actual

        segmentTree[nodoActual].min=min(segmentTree[hijoDer].minimo,segmentTree[hijoIzq].minimo)
    }
}
node query(int inicio,int fin, int nodoActual,int i, int j){
    if(inicio>=i && fin<=j){
        return segmentTree[nodoActual];
    }else{
        int medio=(inicio+fin)/2;
        int hijoIzq=2*nodoActual+1
        int hijoDer=2*nodoActual+2;
        if(j<=medio){
            return query(ini,medio,hijoIzq,i,j);

        }else if(i>=medio){
            return query(medio+1,fin,hijoDer,i,j);
        }else{
            node queryIzq=query(ini,medio,hijoIzq,i,j);
            node queryIzq=query(ini,medio,hijoDer,i,j);

            node resultado;
            resultado.maximo=max(queryIzq.max,queryDer.max);
            resultado.minimo=min(queryIzq.min,queryDer.min);

            return resultado;
            

        }

    }

}
int main(){
    init(0,3,0);
    return 0;
    query(0,7,0,6,7);
}