#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

void displayClubDescription() {
    map<string, string> clubMap;
    ifstream inFile("daiictclubmanager.txt");
    string line;
    while (getline(inFile, line)) {
        if (isdigit(line[0])) {
            size_t pos = line.find('.');
            string clubID = line.substr(0, pos);
            string clubName = line.substr(pos + 1);
            getline(inFile, line);
            clubMap[clubName] = line;
        }
    }
    inFile.close();
    cout << "Enter the name of the club to get its description: ";
    string inputClubName;
    getline(cin, inputClubName);
    auto CN = clubMap.find(inputClubName);
    if (CN != clubMap.end()) {
        cout << "Club Description:" << endl;
        cout << CN->second << endl;
    } else {
        cout << "Club not found." << endl;
    }
}

int main(){
    cout<<"MENU(TYPE THE NUMBER FOR THE INFORMATION YOU NEED):"<<endl;
    cout<<"1.GET CLUB DESCRIPTION BY CLUB NAME"<<endl;
    cout<<"2.GET CLUB DESCRIPTION BY CLUB ID"<<endl;
    cout<<"3.GET WHOLE CLUB LIST"<<endl;
    cout<<"4.GET CLUB LIST USING CLUB CATAGORIES (SCIENCE AND TECHNOLOGY,GAME/SPORTS,ART,CULTURE,FINANCE,PHOTOGRAPHY)"<<endl;
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
            /*
            case 2: {
                string clubID;
                cout << "Enter Club ID: ";
                cin >> clubID;
                displayclubdescriptionbyclubid(clubID);
                break;
            }
            case 3: {
                displayMember();
                break;
            }
            case 4: {
                string clubCategory;
                cout << "Enter Club Category: ";
                cin >> clubCategory;
                displayEvents(clubCategory);
                break;
            }
            */
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
                // Implement display faculty of the club by name
                break;
            }
            case 9: {
                string facultyID;
                cout << "Enter Faculty ID: ";
                cin >> facultyID;
                // Implement display faculty of the club by faculty ID
                break;
            }
            case 10: {
                // Implement event list
                break;
            }
            case 11: {
                // Implement event by date
                break;
            }
            case 12: {
                // Go back to the main menu
                break;
            }
            case 13: {
                cout << "Exiting menu. Goodbye!" << endl;
                return 0;
            }
            default: {
                cout << "Invalid option. Please enter a valid option." << endl;
                break;
            }
        
    } while (option != 13);

    return 0;
}

