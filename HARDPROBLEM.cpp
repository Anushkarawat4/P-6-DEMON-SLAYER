#include <iostream>
#include <string>
using namespace std;

class node {
public:
    string clubname;
    int largescaleevents;
    int mediumscaleevents;
    int smallscaleevents;
    int competitionbonus;
    node* next;

    node(string name, int large, int medium, int small, int bonus) {
        clubname = name;
        largescaleevents = large;
        mediumscaleevents = medium;
        smallscaleevents = small;
        competitionbonus = bonus;
        next = NULL;
    }
};

class ClubFundsDistribution {
public:
    node* head;

    ClubFundsDistribution() {
        head = NULL;
    }

    void addClub(string name, int large, int medium, int small, int bonus) {
        node* newNode = new node(name, large, medium, small, bonus);
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

  void calculateFundsDistribution(long long totalMoney) {
    node* temp = head;
    while (temp != NULL) {
        double fundsDistribution = (5 * temp->largescaleevents) + (3 * temp->mediumscaleevents) + (1.5 * temp->smallscaleevents) + (0.5 * temp->competitionbonus);
        cout << "Club: " << temp->clubname << ", Funds Distribution: " << (fundsDistribution / 10.0 * totalMoney) << endl;
        temp = temp->next;
    }
}

};

int main() {
    int n;
    cout << "Enter the number of clubs: ";
    cin >> n;

    ClubFundsDistribution distribution;

    for (int i = 0; i < n; i++) {
        string name;
        int la, me, sm, cb;
        cout << "Enter club name: ";
        cin >> name;
        cout << "Enter large scale events: ";
        cin >> la;
        cout << "Enter medium scale events: ";
        cin >> me;
        cout << "Enter small scale events: ";
        cin >> sm;
        cout << "Enter competition bonus: ";
        cin >> cb;
        distribution.addClub(name, la, me, sm, cb);
    }

    long long totalmoney;
    cout << "Enter total money: ";
    cin >> totalmoney;

    distribution.calculateFundsDistribution(totalmoney);

    return 0;
}
