#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

// el numero maximo sera 10^18
// 1000000000000000000
string number = "307";
int dp[20][20][20][200];

// modificar el 3er parametro de acuerdo al problema
// 0 true 0
// 0 ....... number



int solve_dp(int pos, int mayor,int impares, int suma) {

    //Modifi
    if(pos > number.size()) { // cuando la posicion exceda al numero dado
        return 0;
    }
    // Modificar de acuerdo al problema
    if(pos == number.size()) {
        // cout<<pares<<endl;
        if(impares >=2) { // tiene 2 o mas impares el numero 
            return 1;
        }
        else {
            return 0;
        }
    }
    if(dp[pos][mayor][impares][suma] == -1) { // Pregunto si no lo he calculado 
        int tope = 9;
        if(mayor == true) {  // el numero que voy a crear puede llegar a ser mayor
            tope = number[pos]-'0';  // solo podemos usar los numeros de 0 al tope -- '3'-'0' =  51 - 48 = 3 
        }
        dp[pos][mayor][impares][suma] = 0;
        for(int digito = 0; digito <= tope; digito++) {
            if(digito == tope ) {
                int total= suma +digito;
                int esImpar = (total > 0) && (!digito%2 == 0);
                dp[pos][mayor][impares][suma] += solve_dp(pos+1, true, impares + esImpar, total );
            }
            else { // 0 1 2 
                
                int total = suma + digito;
                int esImpar = (total > 0) && (!digito%2 == 0);
                dp[pos][mayor][impares][suma] += solve_dp(pos+1, false, impares + esImpar, total);
            }
        }
    }
    return dp[pos][mayor][impares][suma];
}

//MODIDFICAR TERCER PARAMETRO PARA CAMBIAR DE PROBLEMA

int main(){

    //

    int  a = 10;
    int b =19;
    // calculando f(a)
    number = to_string(a-1);
    memset(dp, -1, sizeof(dp));
    int imparesHastaA = solve_dp(0, true, 0,0);
    // calculando f(b)
    memset(dp, -1, sizeof(dp));
    number = to_string(b);
    int imparesHastaB = solve_dp(0, true, 0, 0);
    // total para f(a,b) = f(b) - f(a-1)
    cout<< (imparesHastaB-imparesHastaA);
    return 0;
}