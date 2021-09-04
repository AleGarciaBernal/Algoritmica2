#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>

using namespace std;

int main(){

    int t,n; // 1 ≤ t ≤ 40-> the number of test cases  // n-> the number of phone numbers
    
    string s;
    vector<string> listaDeNumeros;
    bool consistente;

    string cons="YES";
    string incons="NO";

    //si es consistente YES
    //false --> NO
    
    cin>>t;
    
    for(int i=0;i<t;i++){
        cin>>n;
        listaDeNumeros.clear();
        for(int j=0;j<n;j++){
            cin>>s;
            listaDeNumeros.push_back(s);
        }
  
        sort(listaDeNumeros.begin(),listaDeNumeros.end());
        
        consistente=true;
        
        for(int i=0;i<n-1;i++){
            if(listaDeNumeros[i+1].size()>=listaDeNumeros[i].size()){
                s=listaDeNumeros[i+1].substr(0,listaDeNumeros[i].size());
                if(s==listaDeNumeros[i]){
                    consistente=false;
                    break;
                }
            }
        }
        
        if(consistente){
            cout<<cons<<endl;
        } 
        else {
            cout<<incons<<endl;
        }
    }
    
    return 0;
}