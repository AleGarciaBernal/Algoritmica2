//encontrar el prefijo comun mas grande usasndo trie map
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
string findPrefixCommon(){
    node *currentNode = trie;
    string prefix="";
    while(currentNode->mapero.size() == 1 && !currentNode->isWord){
        prefix += currentNode->mapero.begin()->first;
        currentNode = currentNode->mapero.begin()->second;
    }
    return prefix;
}
        
int main() {

    // Inicializar Trie
    init(); 
    string word = "ala";
    insertWord(word);
     word = "alan";
    insertWord(word);
    word = "alanbrito";   
    insertWord(word);
    word="auto";
    insertWord(word);
    cout<<"El prefijo comun es "<<findPrefixCommon();
    return 0;
}