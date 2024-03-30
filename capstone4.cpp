#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class node {
public:
    int key;
    string datastr;
    node* next;
    node(int k, string data) {
        key = k;
        datastr = data;
        next = nullptr;
    }
};

class hashtable {
public:
    int nohashgroups;
    node** table;
    hashtable(int size) {
        nohashgroups = size;
        table = new node*[nohashgroups]();
    }
    int hashfunction(int key) {
        return key % nohashgroups;
    }
    void insertitem_number(int key, string value) {
        int index = hashfunction(key);
        node* n = new node(key, value);
        if (table[index] == nullptr) {
            table[index] = n;
        }
        else {
            n->next = table[index];
            table[index] = n;
        }
    }
void insertitem_name(string key, string value) {
        int index = hashfunction(key);
        node* n = new node(key, value);
        if (table[index] == nullptr) {
            table[index] = n;
        }
        else {
            n->next = table[index];
            table[index] = n;
        }
    }
    bool isempty() {
        for (int i = 0; i < nohashgroups; i++) {
            if (table[i] != nullptr) {
                return false;
            }
        }
        return true;
    }
    void display() {
        for (int i = 0; i < nohashgroups; i++) {
            node* temp = table[i];
            while (temp != nullptr) {
                cout << temp->key << " " << temp->datastr << endl;
                temp = temp->next; // Move to the next node
            }
        }
    }
    string getdata(int key){
        int index=hashfunction(key);
        node* temp=table[index];
        while(temp!=NULL){
            if(temp->key==key){
                return temp->datastr;
            }
            temp=temp->next;
        }
        return;
    }
};
