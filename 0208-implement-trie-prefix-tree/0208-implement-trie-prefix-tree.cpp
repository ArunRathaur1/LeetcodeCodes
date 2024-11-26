#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    char c;
    int end;
    node* ar[26];
    node(char c){
        this->c=c;
        for(int i=0;i<26;i++){
            ar[i]=NULL;
        }
        end=0;
    }
};
class Trie {
    public:
    node* head=new node('1');
    Trie() {
    }
        node* helperadd(char ch, node* head) {
        if (head->ar[ch - 'a'] == NULL) {
            node* newnode = new node(ch);
            head->ar[ch - 'a'] = newnode;
        }
        return head->ar[ch - 'a'];
        }

    void insert(string word) {
        node* tem=head;
        for(int i=0;i<word.length();i++){
            int ch=word[i];
            node* newnode=helperadd(ch,tem);
            tem=newnode;
        }
        tem->end++;
    }
    
    bool search(string word) {
        node* tem=head;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(tem->ar[ch-'a']!=NULL){
                tem=tem->ar[ch-'a'];
            }
            else{
                return false;
            }
        }
        if(tem->end>0)
        return true;
        
        return false;
    }
    
    bool startsWith(string word) {
         node* tem=head;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(tem->ar[ch-'a']!=NULL){
                tem=tem->ar[ch-'a'];
            }
            else{
                return false;
            }
        }
        return true;
        
    }
    void print(){
        int p=-1;
        queue<node*>q;
        q.push(head);
        while(!q.empty()){
            node* t=q.front();
            q.pop();
            if(t==NULL){
                cout<<endl;
                  continue;
            }
            
            cout<<t->c;
            for(int i=0;i<26;i++){
                if(t->ar[i]!=NULL){
                    q.push(t->ar[i]);
                }
            }
            q.push(NULL);
        }
    }
    
};