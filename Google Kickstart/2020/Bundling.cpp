/**
https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3ff3
**/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
    TrieNode* children[26]={NULL};
    long int freq=0;
    vector<char>s;
    TrieNode(){
    }
};
void insertIntoTrie(TrieNode* root , string word){
    TrieNode* curr = root;
    int l = word.size();
    for(int ii =0; ii <l ;ii++){
        int idx = word[ii]-'A';
        if(curr->children[idx]==NULL){
        curr->children[idx]= new TrieNode();
        curr->s.push_back(word[ii]);
       
    }
        curr=curr->children[idx];
        curr->freq+=1;
    }
}
void search(TrieNode* root, long int& l,int& k){
    queue<TrieNode*>q;
    q.push(root);
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        for( auto ch:front->s){
            int m =(front->children[ch -'A']->freq);
            if (m>=k){
                l+= m/k;
                q.push(front->children[ch-'A']);
            }
        }
    }
}
int main()  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >>t;
    int jj=1;
    while(jj<=t){
    int n , k;
    TrieNode* root = new  TrieNode();
    cin >>n>>k;
    int i = n;
    string s;
    while(i--){
        cin>>s;
        insertIntoTrie(root,s);
    }
    long int l =0;
    search(root,l,k);
    cout<<"Case #"<<jj<< ": "<<l<<endl;
    jj++;
}
    return 0;
}
