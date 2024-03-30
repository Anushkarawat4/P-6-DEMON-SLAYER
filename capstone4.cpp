#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class node{
    public:
    int key;
    string datastr;
    node* next;
    node(int k, string data){
        key=k;
        datastr=data;
    }
    };
class hashtable{
    public:
    int nohashgroups;
    node** table;
    hashtable(int size){
        nohashgroups=size;
        table=new node*[nohashgroups]();
    }
    int hashfunction(int key){
        return key% nohashgroups;
    }
    void insertitem(int key , string value){
        int index=hashfunction(key);
        node* n=new node(key,value);
        if(table[index]==NULL){
            table[index]=n;
        }
        else{
            n->next=table[index];
            table[index]=n;
        }
    }
    bool isempty(){
        for(int i=0;i<nohashgroups;i++){
            if(table[i]!=NULL){
                return false;
            }
        }
        return true;
    }
    void display(){
        for(int i=0;i<nohashgroups;i++){
        node* temp=table[i];
        while(temp!=NULL){
         cout<<temp->key<<" "<<temp->datastr<<endl;
        }
        }
    }

};
