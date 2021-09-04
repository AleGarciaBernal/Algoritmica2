#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct dom{
  int x;
  int h;
  int num;
  int id;
}d[100000];

int ans[100000];

int c1(const dom d1,const dom d2){
    if(d1.x<d2.x){
        return 1;

    }else{
        return 0;
    }
}

int main(){
    int n,i;
    cin>>n;
    for(i=0;i<n;i++){
        ans[i]=1;
    }
    for(i=0;i<n;i++){
        cin>>d[i].x>>d[i].h;
        d[i].id=i;
    }
    sort(d,d+n,c1);
    for(i=n-2;i>=0;i--){
        int j=i+1;
        while(j!=n&&d[j].x<d[i].x+d[i].h){
            d[i].num+=d[j].num;
            j=d[j].num+j;
        }
        ans[d[i].id]=d[i].num;
    }
    for(i=0;i<n;i++){
        cout<<ans[i]<<' '<<endl;
        return 0;
    }
}