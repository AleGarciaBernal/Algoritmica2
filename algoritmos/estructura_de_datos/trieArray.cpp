#include <bits/stdc++.h> 
//#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

struct node {
    char currentCharacter;       
    bool finDePalabra=false; // fin de palabra
    int contarPrefijos=0;    
    struct node *children[27];  // [null,null,null,......,null]
    
}*trie; 

// Inicializar 

void init() {
    trie = new node();  // Instanciar el objeto trie
    trie->finDePalabra=false;
    trie->contarPrefijos=0;
}

void insertWord(string word) {   // alba 
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) { // alba
        int character = word[i] - 'a';       // i = 0 'a'-'a' = 0, preguta si en la posicion i existe un nodo
        if(currentNode->children[character] == NULL ) {
            currentNode->children[character] = new node();
            //currentNode->currentCharacter = word[i];
            currentNode->children[character]->contarPrefijos=0;
        }
      //   currentNode = max(currentNode->priority,priority);
        currentNode = currentNode->children[character];// mover el puntero
        currentNode->currentCharacter = word[i];//le pone etiqueta 
        currentNode->contarPrefijos++;
        //currentNode->finDePalabra=false;
    }
    currentNode->finDePalabra = true;
}

bool searchWord(string word) {   // alto 
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) {
        int character = word[i] - 'a';       // i = 0 'a'-'a' = 0
        if(currentNode->children[character] == NULL ) {
           return false;
        }
        currentNode = currentNode->children[character];
    }
    //cout<<currentNode->currentCharacter<<endl;
    return currentNode->finDePalabra;
}

void isThereWord(string word) {
    if(searchWord(word)) {
        cout<<"si existe : "<<word<<" en el trie"<<endl;
    } else {
        cout<<"No Existe : "<<word<<endl;
    }
}

int main() {

    // Inicializar Trie
    init();  
    string word1 = "avion";
    insertWord(word1);
    isThereWord(word1);
    string word2 = "avioneta";   
    insertWord(word2);
    isThereWord(word2);
    isThereWord(word1);
    return 0;
}