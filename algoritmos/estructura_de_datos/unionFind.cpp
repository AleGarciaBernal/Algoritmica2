 #include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int padres[1000];

void init(){
    for(int i=0;i<1000;i++){
        padres[i]=i;  //Todos comienzan siendo padres de si mismos
    }

}
void unir(int vertice1, int vertice2){
    padres[vertice2]=vertice1;

}
int encontrarPadre(int vertice){
    if(padres[vertice]=vertice){
        return vertice;
    }else{
        return encontrarPadre(padres[vertice]);
    }
   
}