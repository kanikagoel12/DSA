#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool eow;
    TrieNode() {
        eow = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
}; class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i]-'a';
            if (p->children[idx] == NULL) {
                p->children[idx] = new TrieNode();
            }
            p = p->children[idx];
        }
        p->eow = true;
    }

    bool search(string word) {
        TrieNode* p = root;
        for(int i=0;i<word.length();i++){
            int idx = word[i]-'a';
            if(p->children[idx] == NULL){
                return false;
            }
            else{
                p = p->children[idx];
                if(i==word.length()-1 and !p->eow){
                    return false;
                }
            }
        }
        return true;
    }

    bool startsWith(string prefix)
    {
        TrieNode* p = root;
        for(int i=0;i<prefix.length();i++){
            int idx = prefix[i]-'a';
            if(p->children[idx] == NULL){
                return false;
            }
            else{
                p = p->children[idx];
            }
        }
        return true;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        if (len == 0) return true;
        for (int i=0;i<len;i++)
        {
            if (search(s.substr(0,i+1)) and wordBreak(s.substr(i+1),wordDict))
            {
                return true;
            }
        }
        return false;
    }
};
int main(){
    vector<string> words = {"the","a","their","any","there"};
    vector<string> words2 = {"i","like","sam","samsung","mobile"};
    Trie* t = new Trie;
    for(int i=0;i<words.size();i++){
        t->insert(words[i]);
    }
    for(int i=0;i<words2.size();i++){
        t->insert(words2[i]);
    }
    cout<<t->search("their")<<endl;
    cout<<t->search("thor")<<endl;
    cout<<t->search("an")<<endl;
    cout<<t->wordBreak("ilikesamsung",words)<<endl;
}