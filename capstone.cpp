/*
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int main(){
    cout<<"MENU(TYPE THE NUMBER FOR THE INFORMATION YOU NEED):"<<endl;
    cout<<"1.GET CLUB DESCRIPTION"<<endl;
    cout<<"2.GET FACULTY OF THE CLUB "<<endl;
    cout<<"3.GET STUDENT MEMBER DESCRIPTION"<<endl;
    cout<<"4.EVENT LIST"<<endl;
    cout<<"5.EDIT CLUB INFORMATION"<<endl;
    cout<<"6.EDIT MEMBER INFORMATION"<<endl;
    cout<<"7.EDIT FACULTY INFORMATION "<<endl;
    cout<<"8.EDIT EVENTS LIST"<<endl;
    cout<<"9.GO BACK TO MENU"<<endl;
    cout<<"10.EXIT MENU"<<endl;


    return 0;
}
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

// Define structures to store club information
struct Club {
    string clubName;
    string description;
};

struct Member {
    int studentID;
    string name;
    string role;
};

struct Faculty {
    string name;
    string clubName;
};

struct Event {
    string eventName;
    string date;
    string description;
};

// Define a map to store clubs' information
unordered_map<int, Club> clubs;
unordered_map<int, vector<Member>> members;
unordered_map<int, vector<Faculty>> faculties;
unordered_map<int, vector<Event>> events;

// Function to read and parse the input text file
void readInputFile(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening file: " << fileName << endl;
        exit(1);
    }

    string line;
    int currentClubID = -1; // Start with -1 as no club is selected initially
    while (getline(file, line)) {
        if (line.empty())
            continue;

        if (line[0] == '~') {
            if (line == "~CLUB INFORMATION") {
                getline(file, line); // Skip the blank line
                currentClubID++; // Increment club ID
                Club club;
                getline(file, club.clubName); // Read club name
                getline(file, club.description); // Read club description
                clubs[currentClubID] = club; // Store club information
            } else if (line == "~MEMBERS INFORMATION OF ALL CLUBS") {
                int srNo, studentID;
                string name, role;
                while (file >> srNo >> studentID >> name >> role) {
                    members[currentClubID].push_back({studentID, name, role}); // Store member information
                }
            } else if (line == "~FACULTY IN CLUBS") {
                int srNo;
                string name, clubName;
                while (file >> srNo >> name >> clubName) {
                    faculties[currentClubID].push_back({name, clubName}); // Store faculty information
                }
            } else if (line == "~EVENT LIST ALL YEAR") {
                int srNo;
                string eventName, date, description;
                while (file >> srNo >> eventName >> date >> description) {
                    events[currentClubID].push_back({eventName, date, description}); // Store event information
                }
            }
        }
    }
    file.close();
}

// Function to display club description
void displayClubDescription(int clubID) {
    cout << "Club Name: " << clubs[clubID].clubName << endl;
    cout << "Description: " << clubs[clubID].description << endl;
}

// Function to display faculty in the club
void displayFaculty(int clubID) {
    cout << "Faculty in the club:" << endl;
    for (const auto& faculty : faculties[clubID]) {
        cout << "Name: " << faculty.name << ", Club: " << faculty.clubName << endl;
    }
}

// Function to display members of the club
void displayMembers(int clubID) {
    cout << "Members of the club:" << endl;
    for (const auto& member : members[clubID]) {
        cout << "Student ID: " << member.studentID << ", Name: " << member.name << ", Role: " << member.role << endl;
    }
}

// Function to display events in the club
void displayEvents(int clubID) {
    cout << "Events in the club:" << endl;
    for (const auto& event : events[clubID]) {
        cout << "Name: " << event.eventName << ", Date: " << event.date << ", Description: " << event.description << endl;
    }
}

int main() {
    // Read and parse the input file
    readInputFile("C:\\Users\\anush\\OneDrive\\Desktop\\daiictclubmanager.txt");

    int option;
    do {
        cout << "\nMENU (TYPE THE NUMBER FOR THE INFORMATION YOU NEED):" << endl;
        cout << "1. Get Club Description" << endl;
        cout << "2. Get Faculty of the Club" << endl;
        cout << "3. Get Student Member Description" << endl;
        cout << "4. Get Event List" << endl;
        cout << "5. Edit Club Information" << endl;
        cout << "6. Edit Member Information" << endl;
        cout << "7. Edit Faculty Information" << endl;
        cout << "8. Edit Events List" << endl;
        cout << "9. Go Back to Menu" << endl;
        cout << "10. Exit Menu" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch(option) {
            case 1: {
                int clubID;
                cout << "Enter Club ID: ";
                cin >> clubID;
                displayClubDescription(clubID);
                break;
            }
            case 2: {
                int clubID;
                cout << "Enter Club ID: ";
                cin >> clubID;
                displayFaculty(clubID);
                break;
            }
            case 3: {
                int clubID;
                cout << "Enter Club ID: ";
                cin >> clubID;
                displayMembers(clubID);
                break;
            }
            case 4: {
                int clubID;
                cout << "Enter Club ID: ";
                cin >> clubID;
                displayEvents(clubID);
                break;
            }
            case 5: {
                // Add functionality to edit club information
                cout << "Functionality to edit club information will be implemented later." << endl;
                break;
            }
            case 6: {
                // Add functionality to edit member information
                cout << "Functionality to edit member information will be implemented later." << endl;
                break;
            }
            case 7: {
                // Add functionality to edit faculty information
                cout << "Functionality to edit faculty information will be implemented later." << endl;
                break;
            }
            case 8: {
                // Add functionality to edit event list
                cout << "Functionality to edit event list will be implemented later." << endl;
                break;
            }
            case 9: {
                // Go back to the main menu
                break;
            }
            case 10: {
                cout << "Exiting menu. Goodbye!" << endl;
                return 0;
            }
            default: {
                cout << "Invalid option. Please enter a valid option." << endl;
            }
        }
    } while (option != 10);

    return 0;
}

