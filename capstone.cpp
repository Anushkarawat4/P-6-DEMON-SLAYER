#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
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
class Event {
public:
    int srNo;
    string eventName;
    int day;
    string month;
    string description;
};

// Function to display the whole club list
void displayEventList() {
    ifstream in("eventlist.txt");
    string line;
    while (getline(in, line)) {
        cout << line << endl;
    }
    in.close();
}

void searchByDateAndMonth() {
    int searchDay;
    string searchMonth;
    cout << "Enter the Date [first input date then month]: ";
    cin >> searchDay >> searchMonth;

    ifstream infile("eventlist.txt");
    if (!infile.is_open()) {
        cerr << "Failed to open the file." << endl;
        return;
    }

    // Read events from the file
    vector<Event> events;
    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        Event event;
        ss >> event.srNo >> event.eventName;
        ss.ignore(); // ignore the dot
        ss >> event.day >> event.month;
        getline(ss, event.description);
        events.push_back(event);
    }

    bool found = false;
    cout << "Events on " << searchDay << " " << searchMonth << ":" << endl;
    for (const auto& event : events) {
        if (event.day == searchDay && event.month == searchMonth) {
            cout << "Event: " << event.eventName << ", Description: " << event.description << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No events found on " << searchDay << " " << searchMonth << endl;
    }
    
    infile.close();
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
            displayEventList();
                break;
            }
            case 10: {
            searchByDateAndMonth();
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
