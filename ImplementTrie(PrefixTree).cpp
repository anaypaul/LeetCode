#include <unordered_map>
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode(char val) : val{val}, isEndOfWord{false} {}
    char val;
    bool isEndOfWord;
    unordered_map<char,TrieNode*> children;
};

class Trie {
public:
    Trie (){
        root = new TrieNode(' ');
    }
    
    void insert(string word){
        unordered_map<char,TrieNode*>::iterator itr;
        TrieNode * curr = root;
        for(int i = 0; i<word.size(); i++){
            itr = curr->children.find(word[i]); 
            if(itr == curr->children.end()){
                curr->children[word[i]] = new TrieNode(word[i]);
            }
            curr = curr->children[word[i]];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word){
        unordered_map<char,TrieNode*>::iterator itr;
        TrieNode * curr = root;
        for(int i = 0; i<word.size(); i++){
            itr = curr->children.find(word[i]);
            if( itr == curr->children.end()){
                return false;
            }
            curr = curr->children[word[i]];
        }
        if(curr != nullptr && curr->isEndOfWord){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix){
        unordered_map<char,TrieNode*>::iterator itr;
        TrieNode * curr = root;
        for(int i = 0; i<prefix.size(); i++){
            itr = curr->children.find(prefix[i]);
            if( itr == curr->children.end()){
                return false;
            }
            curr = curr->children[prefix[i]];
        }
        if(curr == nullptr){
            return false;
        }
        return true;
    }

private:
    
    TrieNode* startsWithHelper(string prefix){
        
        TrieNode* curr = root;
        
        unordered_map<char,TrieNode*>::iterator itr;
        for (char ch : prefix){
            itr = curr->children.find(ch);
            if (itr == curr->children.end()){
                return NULL;
            }
            curr = curr->children[ch];
        }
        
        return curr;
    }
    
    TrieNode* root;
};