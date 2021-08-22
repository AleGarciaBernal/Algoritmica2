#include <iomanip>
#include<iostream>
#include<vector>

void mostrarVector(const std::vector<int>& v){
    for(const int& i:v){
        std::cout<<std::setw(3)<<i;
    }
    std::cout<<std::endl;

}

bool esValid(const std::vector<int>& v){
    
    int valor=v.back();
    //Horizontal
    for (std ::size_t i = 0; i < v.size(); ++i) {
        if(v[i]==valor){
            return false;
        }
    }
    //diagonal

    int predetermin=1;
    for (int i = v.size()-2;i>=0;--i){
        if(v[i]==valor){
            return false;
        }
        if(valor==v[i]-predetermin){
            return false;
        }
        if(valor==v[i]-predetermin){
            return false;
        }
        ++predetermin;
    }
    return true;
}
void ochoReinas(std::vector<int>& v, int reinasQueFaltanAgregar , int reinas ){
    if(reinasQueFaltanAgregar==0){
        mostrarVector(v);
        return;
    }
    v.push_back(0);
    for(int i=0;i<reinas;++i){
        v.back()=i;
        if(esValid(v)){
            ochoReinas(v,reinasQueFaltanAgregar-1,reinas);
        }
    }
    v.pop_back();
}
void ochoReinas(int n){
    std::vector<int> v;
    v.reserve(n);
    ochoReinas(v,n,n);
}
int main(){
    ochoReinas(8);
    return 0;
    boolean 

}
