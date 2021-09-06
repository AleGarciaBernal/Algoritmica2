#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int n;// tamaño del arreglo
int x;//el que queremos encontrar
int A[100000];

bool f(int number) {
    return number > x;//preguntamos es mayor a x
}

void bs() {//binari search
    int ini = 0;//comienzo del proceso, arregllo entero
    int fin = n - 1;//n es el tamaño del arreglo
    while(ini < fin ) {//mientras no sean iguales
        int mid = (ini + fin) / 2;//tomamos la parte entera para el mid
        if(f(A[mid])) {//llamamos a f, preguntamos si la posicion donde estamos es mayor a a X
            fin = mid;// si 
        } else {
            ini = mid + 1;
        }
    }
    if(f(A[fin])) {
        cout<<A[fin]<<endl;
    }else {
        cout<<"No hay elementos mayores"<<endl;
    }
}

int main() {
    input;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>A[i];//leyendo el vector
    }
     
    cin>>x;
    bs();
    return 0;
}