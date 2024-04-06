#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

void readstudent_info(unordered_map<int, string>& s_names, unordered_map<string, int>& s_ids) {
    ifstream infile("membership_data.txt");
    string line;

    while (getline(infile, line) && line != "[Members]") {}

    // Read member data
    while (getline(infile, line) && line != "") {
        // Check if the line contains specific keywords to skip
        if (line.find("ID,Name") != string::npos) continue;

        stringstream ss(line);
        int id;
        string name;
        if (ss >> id >> ws && getline(ss, name)) {
            s_names[id] = name;
            s_ids[name] = id;  
        } else {
            cerr << "Error reading line: " << line << endl;
        }
    }
    infile.close();
}
void read_stuMemberships(unordered_map<int, vector<string>>& s_membership) {
    ifstream infile("membership_data.txt");
    string line;

    // Skip lines until the [Memberships] section
    while (getline(infile, line) && line != "[Memberships]") {}

    // Read membership data
    while (getline(infile, line) && line != "") {
        // Check if the line contains specific keywords to skip
        if (line.find("Member ID,Club Name,Role (Optional)") != string::npos) continue;

        stringstream ss(line);
        int id;
        string club_name, role;
        if (ss >> id >> club_name >> role) {
            s_membership[id].push_back(club_name + " (" + role + ")");
        } else {
            cerr << "Error reading line: " << line << endl;
        }
    }
    infile.close();
}
void searchStudentByID(const unordered_map<int, string>& s_names, const unordered_map<int, vector<string>>& s_membership, int id) {
    auto name_iter = s_names.find(id);
    auto membership_iter = s_membership.find(id);

    if (name_iter != s_names.end()) {
        cout << "Student found:" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name_iter->second << endl;
        if (membership_iter != s_membership.end()) {
            cout << "Memberships:" << endl;
            for (const string& membership : membership_iter->second) {
                cout << membership << endl;
            }
        } else {
            cout << "No memberships found." << endl;
        }
    } else {
        cout << "Student with ID " << id << " not found." << endl;
    }
}
void searchStudentByName(const unordered_map<int, string>& s_names, const unordered_map<int, vector<string>>& s_membership, const unordered_map<string, int>& s_ids, const string& name) {
    bool found = false;
    for (const auto& student : s_names) {
        if (student.second.find(name) != string::npos) {
            int id = student.first;
            searchStudentByID(s_names, s_membership, id);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student with name " << name << " not found." << endl;
    }
}





void displayClubDescription() {
    unordered_map<string, string> clubmap;
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
void getinfobyclubname() {
    unordered_map<string, string> clubmap;
    ifstream in("facultymentor.txt");
    string clubname, facultyname, id, info;

    while (getline(in, clubname)) {
        getline(in, facultyname);
        getline(in, id);
        info = facultyname + " " + id;
        clubmap[clubname] = info;
    }
    in.close();


    cout << "ENTER CLUB NAME IN CAPITAL TO GET FACULTY MENTOR INFORMATION: ";
    string inputclubname;
    getline(cin, inputclubname);


    auto CN = clubmap.find(inputclubname);
    if (CN != clubmap.end()) {
        cout << "FACULTY INFORMATION IS AS FOLLOWS:" << endl;
        cout << CN->second << endl;
    } else {
        cout << "CLUB NAME NOT FOUND IN DATABASE." << endl;
    }
}


void getinfobyfacultyname(){
    unordered_map<string, string> clubmap;
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
     unordered_map<string, string> clubmap;
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
void studentlist_byclub(const unordered_map<int, string>& s_names, const string& club_name) {
    ifstream infile("student_dataclub.txt");
    string line;
    bool found = false;

    while (getline(infile, line)) {
        if (line == ("#" + club_name)) {
            found = true;
            cout << "Student list for club '" << club_name << "':" << endl;
            cout << "->" << endl;
            while (getline(infile, line) && !line.empty()) {
                cout << "-> " << line << endl;
                size_t comma_pos = line.find(",");
                if (comma_pos != string::npos) {
                    string student_info = line.substr(comma_pos + 1);
                    int student_id = stoi(student_info.substr(student_info.find("ID") + 3));
                    string student_name = line.substr(0, comma_pos);
                    auto student_iter = s_names.find(student_id);
                    if (student_iter != s_names.end()) {
                        cout << "Student ID: " << student_id << ", Student Name: " << student_name << endl;
                    }
                }
            }
            break;
        }
    }

    infile.close();

    if (!found) {
        cout << "Club '" << club_name << "' not found or has no members." << endl;
    }
}

int main() {
  unordered_map<int, string> s_names;
    unordered_map<int, vector<string>> s_memberships;
    unordered_map<string, int> s_ids;  // Map to store student names with their IDs
    readstudent_info(s_names, s_ids);
    read_stuMemberships(s_memberships);
    int option;
    while(option!=10){
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
        int sid;
            cout << "Enter student ID: ";
            cin >> sid;
            cin.ignore();
            searchStudentByID(s_names, s_memberships, sid);
        break;
    }
    case 5: {
        string sname;
            cout << "Enter student name: ";
            getline(cin, sname);
            searchStudentByName(s_names, s_memberships, s_ids, sname);
            break;
        break;
    }
    case 6: {
        string club_name;
            cout << "Enter the name of the club to get the student list: (enter the club name as shown in the club list)";
            getline(cin, club_name);
            studentlist_byclub(s_names, club_name);
            
        break;
    }
    case 7: {
        getinfobyfacultyid();
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
    }

    return 0;
}
