#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 
#define MAX_N 1001     
//INTERNET BANDWIDTH UVA 820 resuelto con Edmonds Karp
int grafo[MAX_N][MAX_N];   
int path[MAX_N];            

int maxFlow(int s,int t) { 
   
    int maxFlow = 0;
    while(true) { 
        memset(path, -1, sizeof(path)); 
        queue<int> Q;
        Q.push(s);
        path[s] = s;  
        while(!Q.empty() && path[t]==-1) { 
            int currentNode = Q.front(); 
            Q.pop(); 
            for(int i = 0 ; i < MAX_N ; i++) { 
                if(grafo[currentNode][i] > 0 && path[i]==-1)  {  
                    path[i] = currentNode;                       
                    Q.push(i);                                  
                }   
            }
        }
       
        if(path[t]==-1) {
            break;
        }

        int minFlow = 1e9; 

        for(int from = path[t],to = t; from!=to ; from = path[to = from]) {
            minFlow = min(minFlow,grafo[from][to]); 
        }
        
        
        for(int from = path[t],to = t; from!=to ; from = path[to = from]) {
            grafo[from][to] -= minFlow; 
            grafo[to][from] += minFlow;
        }
       
        maxFlow += minFlow;
      
    }
  
    return maxFlow;
}

int main() {
input;
int nodes, aristas, nroCases = 1; 
while(cin>>nodes && nodes) {
    int s,t;    
    cin>>s>>t>>aristas;
    memset(grafo,0,sizeof(grafo));
     for(int i=0;i<aristas;i++) {
        int from, to, capacity; 
        cin>>from>>to>>capacity;
        grafo[from][to] += capacity;           
        grafo[to][from] += capacity;                
    }
    cout << "Network " << nroCases++ << endl;
    cout<<"The bandwidth is "<< maxFlow(s, t)<< "." <<endl<<endl;
    }
    return 0;    
}