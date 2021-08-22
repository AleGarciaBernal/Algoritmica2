#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int numberOfNodes = 0;
struct node

{
    map<char, node*> mapero;
    bool isWord;                
} *trie;

void init()
{
    trie = new node();
    trie->isWord = false;
    numberOfNodes++;
}

void insertWord(string word)
{
    node *currentNode = trie;  
    for (int i = 0; i < word.length(); i++)
    {
        
        //    if (!currentNode->mapero[word[i]])
        if(currentNode->mapero.find(word[i]) == currentNode->mapero.end())
        {
            currentNode->mapero[word[i]] = new node();
            numberOfNodes++;
        }
        currentNode = currentNode->mapero[word[i]];
    }
    currentNode->isWord=true;
    cout<<"Se insertoi la palabra "<<word<<endl;
}

int main() {

    // Inicializar Trie
    init(); 
    string word1 = "alto";
    insertWord(word1);
    string word2 = "auto";
    insertWord(word2);
    string word3 = "automovil";   
    insertWord(word3);
    cout<<"Hay "<<numberOfNodes++<<" nodos"<<endl;
    return 0;
}