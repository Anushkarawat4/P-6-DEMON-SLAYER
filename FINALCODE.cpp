#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class node {
public:
    string key;
    string datastr;
    node* next;
    node(string k, string data) {
        key = k;
        datastr = data;
        next = nullptr;
    }
};

class hashtable {
public:
    int numberofhash;
    node** table;
    hashtable(int size) {
        numberofhash = size;
        table = new node*[numberofhash](); 
    }
    int hashfunction(string key) {
        int sum = 0;
        for (int i = 0; i < key.size(); i++) {
            char c = key[i];
            sum += c;
        }
        return sum % numberofhash;
    }
    int insertdata(string key, string value) {
        int index = hashfunction(key);
        node* n = new node(key, value);
        if (table[index] == NULL) {
            table[index] = n;
        }
        else {
            node* temp = table[index];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = n; // Set the next pointer of the last node
        }
    }
    string getdata(string key) {
        int index = hashfunction(key);
        node* temp = table[index];
        while (temp != NULL) {
            if (temp->key == key) {
                return temp->datastr;
            }
            temp = temp->next;
        }
        return "";
    }
        string getitem(string key) {
        int index =0;
        for(index=0;index<20;index++){
        node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->datastr; // Return the value corresponding to the key
            }
            current = current->next;
        }
        }
        return ""; // Return empty string if key not found
    }
};

void displayclubbyclubname(hashtable& ht) {
    ifstream in("daiictclubmanager.txt");
    string clubname, description,line;
    while (getline(in, clubname)) {
        getline(in, description);
        getline(in,line);
        ht.insertdata(clubname, description);
       
    }
    in.close();
}
void diplayclublist(){
    ifstream in("daiictclubmanager.txt");
    string clubname, description,line;
    for(int i =1 ; i<=19;i++){
    getline(in, clubname);
        getline(in, description);
        getline(in,line);
     
        cout<<i<<"."<<clubname<<endl;
        }
        in.close();
        
}
void clubusingcat(){
        char q;
    ifstream in("daiictclubmanagercat.txt");
    string s1,s2,s3,s4,s5,s6;
    cout<<"ENTER (A,B,C,D,E,F):";
    cin>>q;
     getline(in,s1);
     getline(in,s2);
     getline(in,s3);
     getline(in,s4);
     getline(in,s5);
     getline(in,s6);
    if(q=='A'){
     cout<<s1<<endl;
    }
    else if(q=='B'){
     cout<<s2<<endl;
    }
    else if(q=='C'){
     cout<<s3<<endl;
    }
    else if(q=='D'){
     cout<<s4<<endl;
    }
    else if(q=='E'){
     cout<<s5<<endl;
    }
    else if(q=='F'){
     cout<<s6<<endl;
    }
    in.close();
}

void getinfobyfacultyid(hashtable& a){
    ifstream in("facultymentor.txt");
    string id, clubname, facultyname,info;
    while(getline(in,clubname))
    {
        getline(in,facultyname);
        getline(in,id);
        info= clubname + " " + facultyname;
        a.insertdata(id,info);
    }
    in.close();
    
    string input;
    cout<<"ENTER FACULTY MENTOR'S ID FOR FACULTY MENTOR INFORMATION : ";
    cin>> input;
    string output = a.getdata(input);
    if(output != "")
    {
        cout<<"FACULTY INFORMATION IS AS FOLLOWS: "<<output<<endl;
    }
    else
    {
        cout<<"FACULTY ID NOT FOUND IN DATABASE."<<endl;
    }
}

void getinfobyfacultyname(hashtable& a){
    ifstream in("facultymentor.txt");
    string id, clubname, facultyname,info;
    while(getline(in,clubname))
    {
        getline(in,facultyname);
        getline(in,id);
        info= clubname + " " + id;
        a.insertdata(facultyname,info);
    }
    in.close();
    
    string input;
    cout<<"ENTER FACULTY MENTOR'S NAME IN CAPITAL FOR FACULTY MENTOR INFORMATION: ";
    cin>> input;
    string output = a.getdata(input);
    if(output != "")
    {
        cout<<"FACULTY INFORMATION IS AS FOLLOWS: "<<output<<endl;
    }
    else
    {
        cout<<"FACULTY NAME NOT FOUND IN DATABASE."<<endl;
    }
}

void getinfobyclubname(hashtable& a){
    ifstream in("facultymentor.txt");
    string id, clubname, facultyname,info;
    while(getline(in,clubname))
    {
        getline(in,facultyname);
        getline(in,id);
        info= facultyname + " " + id;
        a.insertdata(clubname,info);
    }
    in.close();
    
    string input;
    cout<<"ENTER CLUB NAME IN CAPITAL TO GET FACULTY INFORMATION:  ";
    cin>> input;
    string output = a.getdata(input);
    if(output != "")
    {
        cout<<"FACULTY INFORMATION IS AS FOLLOWS: "<<output<<endl;
    }
    else
    {
        cout<<"CLUB DOES NOT EXIST."<<endl;
    }
}

int main() {
    cout << "MENU[TYPE ALL INFORMATION IN CAPITAL]:" << endl;
    cout << "1.ENTER CLUB NAME TO GET ITS DESCRIPTION:" << endl;
    cout << "2.GET WHOLE CLUB LIST:" << endl;
    cout << "3.GET CLUB LIST USING CLUB CATAGORIES (A.SCIENCE AND TECHNOLOGY,B.GAME/SPORTS,C.ART,D.CULTURE,E.FINANCE,F.PHOTOGRAPHY AND MEDIA):" << endl;
    cout << "4.ENTER STUDENT ID FOR GETTING STUDENT INFORMATION:" << endl;
    cout << "5.ENTER STUDENT NAME FOR GETTING STUDENT INFORMATION" << endl;
    cout << "6.ENTER CLUB NAME TO GET THE STUDENT LIST:" << endl;
    cout << "7.ENTER FACULTY MENTOR ID FOR FACULTY MENTOR INFORMATION:" << endl;
    cout << "8.ENTER CLUB NAME TO GET THE FACULTY MENTOR:" << endl;
    cout << "9.ENTER FACULTY MENTOR NAME TO GET THE CLUB NAME: " << endl;
    cout << "10.EXIT THE MENU:" << endl;
    cout << "ENTER THE NUMBER OF SERVICE YOU WANT" << endl;
    int option;
    cin >> option;
    cin.ignore();
    switch (option) {
    case 1: {
        hashtable ht(20);
        displayclubbyclubname(ht);
        string club;
        cout << "ENTER THE NAME FOR THE CLUB IN CAPITAL(EXAMPLE:CHESS CLUB):" << endl;
        getline(cin, club); // Read club name from user
        string description = ht.getitem(club);
        if(description!=""){
        cout << "DESCRIPTION:" << description << endl;
        }
        else{
            cout<<"CLUB DOES NOT EXIST"<<endl;
        }
        break;
    }
    case 2: {
        diplayclublist();
        break;
    }
    case 3: {
        clubusingcat();
        break;
    }
    case 4: {
        break;
    }
    case 5: {
        break;
    }
    case 6: {
        break;
    }
    case 7: {
        hashtable a(20);
        getinfobyfacultyid(a);
        break;
    }
    case 8: {
        hashtable b(20);
        getinfobyclubname(b);
        break;
    }
    case 9: {
        hashtable c(20);
        getinfobyfacultyname(c);
        break;
    }
    case 10: {
        cout << "EXITING MENU. THANKS FOR USING THE SERVICE" << endl;
        break;
    }
    }

    return 0;
}
