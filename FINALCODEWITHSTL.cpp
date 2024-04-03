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



int main(){
    cout<<"MENU(TYPE THE NUMBER FOR THE INFORMATION YOU NEED):"<<endl;
    cout<<"1.ENTER CLUB NAME TO GET ITS DESCRIPTION:"<<endl;
    cout<<"2.ENTER CLUB ID [1-19] TO GET ITS DESCRIPTION:"<<endl;
    cout<<"3.GET WHOLE CLUB LIST:"<<endl;
    cout<<"4.GET CLUB LIST USING CLUB CATAGORIES (A.SCIENCE AND TECHNOLOGY,B.GAME/SPORTS,C.ART,D.CULTURE,E.FINANCE,F.PHOTOGRAPHY AND MEDIA):"<<endl;
    cout<<"5.ENTER STUDENT ID FOR GETTING STUDENT INFORMATION:"<<endl;
    cout<<"6.ENTER STUDENT NAME FOR GETTING STUDENT INFORMATION:"<<endl;
    cout<<"7.ENTER CLUB NAME TO GET CLUB FACULTY:"<<endl;
    cout<<"8.ENTER FACULTY ID FOR FACULTY INFORMATION:"<<endl;
    cout<<"9: WHOLE LIST OF EVENTS:"<<endl;
    cout<<"10.GIVE EVENTS NAME BY DATE:"<<endl;
    cout<<"11.EXIT THE MENU:"<<endl;
    int option;
    cin>>option;
    cin.ignore();

switch(option) {
            case 1: {
                displayClubDescription();
                break;
            }
            
            case 2: {
             
                break;
            }
            
            case 3: {
                 displayClubDescription();
                break;
            }
        
            case 4: {
                clubusingcat();
                break;
            }
            
            case 5: {
             
                break;
            }
            case 6: {
             
                break;
            }
            case 7: {
               
                break;
            }
            case 8: {
   
                break;
            }
            case 9: {
          
                break;
            }
            case 10: {
        
                break;
            }
        
            case 11: {
                cout << "EXITING MENU. THANKS FOR USING." << endl;
                return 0;
            }
            default: {
                cout << "INVALID OPTION" << endl;
                break;
            }
        
    } while (option != 11);

    return 0;
}
