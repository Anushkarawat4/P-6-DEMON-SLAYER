#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

void displayClubDescription() {
    map<string, string> clubmap;
   ifstream in("daiictclubmanager.txt");
    string clubname, description,line;
    while (getline(in, clubname)) {
        getline(in, description);
        getline(in,line);
            clubmap[clubname] = description;
        }
    
    in.close();
    cout << "Enter the name of the club to get its description: ";
    string inputclubname;
    getline(cin, inputclubname);
    auto CN = clubmap.find(inputclubname);
    if (CN != clubmap.end()) {
        cout << "Club Description:" << endl;
        cout << CN->second << endl;
    } else {
        cout << "Club not found." << endl;
    }
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
void getinfobyclubname(){
    map<string, string> clubmap;
    ifstream in("facultymentor.txt");
    string id, clubname, facultyname,info;
    while(getline(in,clubname))
    {
        getline(in,facultyname);
        getline(in,id);
        info= facultyname + " " + id;
        clubmap[clubname]=info;
    }
    in.close();
    
    cout <<"ENTER CLUB NAME IN CAPITAL TO GET FACULTY MENTOR INFORMATION: ";
    string inputclubname;
    getline(cin, inputclubname);
    auto CN = clubmap.find(inputclubname);
    if (CN != clubmap.end()) {
        cout <<"FACULTY INFORMATION IS AS FOLLOWS:"<< endl;
        cout << CN->second << endl;
    } else {
        cout << "CLUB DOES NOT EXIST."<< endl;
    }
}

void getinfobyfacultyname(){
    map<string, string> clubmap;
    ifstream in("facultymentor.txt");
    string id, clubname, facultyname,info;
    while(getline(in,clubname))
    {
        getline(in,facultyname);
        getline(in,id);
        info= clubname + " " + id;
        clubmap[facultyname]=info;
    }
    in.close();
    
 cout <<"ENTER FACULTY MENTOR'S NAME TO GET FACULTY INFORMATION: ";
    string inputclubname;
    getline(cin, inputclubname);
    auto CN = clubmap.find(inputclubname);
    if (CN != clubmap.end()) {
        cout <<"FACULTY INFORMATION IS AS FOLLOWS: "<< endl;
        cout << CN->second << endl;
    } else {
        cout <<"FACULTY NAME NOT FOUND IN DATABASE."<< endl;
    }
}

void getinfobyfacultyid(){
     map<string, string> clubmap;
    ifstream in("facultymentor.txt");
    string id, clubname, facultyname,info;
    while(getline(in,clubname))
    {
        getline(in,facultyname);
        getline(in,id);
        info= clubname + " " + facultyname;
        clubmap[id]=info;
    }
    in.close();
    
 cout <<"ENTER FACULTY MENTOR'S ID TO GET FACULTY INFORMATION: ";
    string inputclubname;
    getline(cin, inputclubname);
    auto CN = clubmap.find(inputclubname);
    if (CN != clubmap.end()) {
        cout <<"FACULTY INFORMATION IS AS FOLLOWS: "<< endl;
        cout << CN->second << endl;
    } else {
        cout <<"FACULTY ID NOT FOUND IN DATABASE."<< endl;
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
    cout << "7.ENTER FACULTY ID FOR FACULTY INFORMATION:" << endl;
    cout << "8.ENTER CLUB NAME TO GET THE FACULTY:" << endl;
    cout << "9.ENTER FACULTY NAME TO GET THE CLUB NAME: " << endl;
    cout << "10.EXIT THE MENU:" << endl;
    cout << "ENTER THE NUMBER OF SERVICE YOU WANT" << endl;
    int option;
    cin >> option;
    cin.ignore();
    switch (option) {
    case 1: {
        displayClubDescription() ;
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
        getinfobyfacultyname();
        break;
    }
    case 8: {
        getinfobyclubname();
        break;
    }
    case 9: {
        getinfobyfacultyname();
        break;
    }
    case 10: {
        cout << "EXITING MENU. THANKS FOR USING THE SERVICE" << endl;
        break;
    }
    }

    return 0;
}
