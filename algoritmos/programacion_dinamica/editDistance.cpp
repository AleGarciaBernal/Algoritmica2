#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

string wordA,wordB;

int solve(int posA,int posB){
    if(posA==0){
        return posB;
    }
    if(posB==0){
        return posA;
    }
    int minimoEditDistance=1000000;
    
    int sonDiferentes=wordA[posA]!=wordB[posB];//TRue or fALSE

    minimoEditDistance=min(minimoEditDistance,solve(posA-1,posB-1)+sonDiferentes);
    minimoEditDistance=min(minimoEditDistance,solve(posA-1,posB)+1);
    minimoEditDistance=min(minimoEditDistance,solve(posA,posB-1)+1);

    return minimoEditDistance;

}
int main(){
    wordA="AE";
    wordB="A";

    cout<<solve(wordA.length()-1,wordB.length()-1)<<endl;

    return 0;
}