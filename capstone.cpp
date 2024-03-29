#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

void displayClubDescription() {
    map<string, string> clubmap;
    ifstream in("daiictclubmanager.txt");
    string line ,clubid,clubname;
    int pos;
    while (getline(in, line)) {
        if (isdigit(line[0])) {
            pos = line.find('.');
            clubid = line.substr(0, pos);
            clubname = line.substr(pos + 1);
            getline(in, line);
            clubmap[clubname] = line;
        }
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
void displayclubbyclubid(){
    
map<int,string>clubmap;
map<string, int> :: iterator i;
ifstream in("daiictclubmanager.txt");
string line;
while(getline(in,line)){
    if(isdigit(line[0])){
        int clubid=stoi(line);
        getline(in,line);
        clubmap[clubid]=line;
    }
}
in.close();
cout<<"Enter club ID to get it's description:"<<endl;
int inputid;
cin>>inputid;
auto itr=clubmap.find(inputid);
if(itr!=clubmap.end()){
cout<<"CLUB DESCRIPTION:"<<endl;
cout<<itr->second<<endl;
}
else{
    cout << "Club not found." << endl;
}

}
void wholeclublist(){
        ifstream in("daiictclubmanager.txt");
    string line ,clubid,clubname;
    int pos;
    while (getline(in, line)) {
        if (isdigit(line[0])) {
            pos = line.find('.');
            clubid = line.substr(0, pos);
            clubname = line.substr(pos + 1);
            cout<<clubid<<" "<<clubname<<endl;
                    }
    }
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

int main(){
    cout<<"MENU(TYPE THE NUMBER FOR THE INFORMATION YOU NEED AND ENTER ALL INFORMATION IN CAPSLOCK):"<<endl;
    cout<<"1.GET CLUB DESCRIPTION BY CLUB NAME"<<endl;
    cout<<"2.GET CLUB DESCRIPTION BY CLUB ID"<<endl;
    cout<<"3.GET WHOLE CLUB LIST"<<endl;
    cout<<"4.GET CLUB LIST USING CLUB CATAGORIES (A.SCIENCE AND TECHNOLOGY,B.GAME/SPORTS,C.ART,D.CULTURE,E.FINANCE,F.PHOTOGRAPHY AND MEDIA)"<<endl;
    cout<<"5.SEARCH STUDENT BY STUDENT ID"<<endl;
    cout<<"6.SEARCH STUDENT BY STUDENT NAME"<<endl;
    cout<<"7..GET FACULTY LIST OF THE CLUB "<<endl;
    cout<<"8.GET FACULTY OF THE CLUB BY NAME"<<endl;
    cout<<"9.GET FACULTY OF CLUB BY FACULTY ID"<<endl;
    cout<<"10.EVENT LIST"<<endl;
    cout<<"11.EVENT BY DATE:"<<endl;
    cout<<"12.GO BACK TO MENU"<<endl;
    cout<<"13.EXIT MENU"<<endl;
    int option;
    cin>>option;
    cin.ignore();

switch(option) {
            case 1: {
                displayClubDescription();
                break;
            }
            
            case 2: {
                displayclubbyclubid();
                break;
            }
            
            case 3: {
                 wholeclublist();
                break;
            }
        
            case 4: {
                clubusingcat();
                break;
            }
            
            case 5: {
                string studentID;
                cout << "Enter Student ID: ";
                cin >> studentID;
                // Implement search by student ID
                break;
            }
            case 6: {
                string studentName;
                cout << "Enter Student Name: ";
                cin >> studentName;
                // Implement search by student name
                break;
            }
            case 7: {
                string clubName;
                cout << "Enter Club Name: ";
                cin >> clubName;
                // Implement display faculty list of the club
                break;
            }
            case 8: {
                string facultyName;
                cout << "Enter Faculty Name: ";
                cin >> facultyName;
               
                break;
            }
            case 9: {
                string facultyID;
                cout << "Enter Faculty ID: ";
                cin >> facultyID;
                
                break;
            }
            case 10: {
            
                break;
            }
            case 11: {
            
                break;
            }
        
            case 12: {
                cout << "Exiting menu. Goodbye!" << endl;
                return 0;
            }
            default: {
                cout << "Invalid option. Please enter a valid option." << endl;
                break;
            }
        
    } while (option != 12);

    return 0;
}
