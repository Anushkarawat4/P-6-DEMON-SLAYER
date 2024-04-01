#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include<map>

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
    void insertdata(string key, string value) {
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
            temp->next = n; 
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
                return current->datastr; 
            }
            current = current->next;
        }
        }
        return "";
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
    cout<<"ENTER CLUB NAME IN CAPITAL TO GET FACULTY MENTOR INFORMATION: ";
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
    cout<<"ENTER FACULTY MENTOR'S NAME TO GET FACULTY INFORMATION: ";
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
    cout<<"ENTER FACULTY MENTOR'S ID TO GET FACULTY INFORMATION: ";
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
void readstudent_info(unordered_map<int, string>& s_names, unordered_map<string, int>& s_ids) {
    ifstream infile("membership_data.txt");
    string line;

    // Skip lines until the [Members] section
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
            s_ids[name] = id;  // Store ID with corresponding name
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


int main() {
    // Declarations
    unordered_map<int, string> s_names;
    unordered_map<int, vector<string>> s_memberships;
    unordered_map<string, int> s_ids;  // Map to store student names with their IDs
    

  
    readstudent_info(s_names, s_ids);
    read_stuMemberships(s_memberships);
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
        hashtable ht(20);
        displayclubbyclubname(ht);
        string club;
        cout << "ENTER THE NAME FOR THE CLUB IN CAPITAL(EXAMPLE:CHESS CLUB):" << endl;
        getline(cin, club);
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
       // Search student by ID
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
        }
        case 6: {

            break;
        }
    case 7: {
        hashtable a(19);
        getinfobyfacultyid(a);
        break;
    }
    case 8: {
        hashtable b(19);
        getinfobyclubname(b);
        break;
    }
    case 9: {
        hashtable c(19);
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
