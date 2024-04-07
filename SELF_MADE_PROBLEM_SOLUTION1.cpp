//SOLUTION BY MAKING A UNTRADITIONAL DATA STRUCTURE NAMED MONEYDIVIDER
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class MoneyDivider {
public:
    map<string, float> moneyDistribution(float totalMoney) {
        map<string, float> clubMap;
        ifstream in("clubmoney.txt");
        if (!in) {
            cerr << "Error opening file." << endl;
            return clubMap;
        }

        string clubName, ls, ms, ss, cb;
       cout<<"MONEY DISTRIBUTION FOR ALL CLUBS"<<endl;
        while (getline(in, clubName)) {
            if (!getline(in, ls) || !getline(in, ms) || !getline(in, ss) || !getline(in, cb)) {
                cerr << "Error reading data for club: " << clubName << endl;
                continue;
            }

            int large = stoi(ls);
            int med = stoi(ms);
            int small = stoi(ss);
            int bonus = stoi(cb);

            float reservedMoney = totalMoney * 30 / 100;
            float availableMoney = totalMoney - reservedMoney;

            float moneyForLarge = (large * 5) / 14.0;
            float moneyForMedium = (med * 3) / 25.0;
            float moneyForSmall = (small * 1.5) / 30.0;
            float moneyForBonus = (bonus * 0.5) / 13.0;

            float totalMoneyForClubs = ((moneyForLarge + moneyForMedium + moneyForSmall + moneyForBonus) * (availableMoney / 10));

            // Distribute total money for clubs equally among clubs
            clubMap[clubName] = totalMoneyForClubs + (reservedMoney / 19);
            
            cout << clubName << "~" << clubMap[clubName] << endl;
        }

        float totalDistributedMoney = 0.0;
        for (const auto& pair : clubMap) {
            totalDistributedMoney += pair.second;
        }
        cout << "Total distributed money: " << totalDistributedMoney << endl;

        in.close();
        return clubMap;
    }

    void getClubMoney( map<string, float>& clubMap, string& clubName) {
        auto it = clubMap.find(clubName);
        if (it != clubMap.end()) {
            cout << "Money for the club " << clubName << ": " << it->second << endl;
        } else {
            cout << "Club not found." << endl;
        }
    }
};

int main() {
    MoneyDivider md;
    float totalMoney;
    cout<<"INPUT THE TOTAL AMOUNT OF MONEY TO BE DISTRIBUTED:"<<endl;
    cin>>totalMoney; 
    auto clubMap = md.moneyDistribution(totalMoney);

    string clubName;
    cout << "Enter the name of the club to get its money: ";
    getline(cin, clubName);

    md.getClubMoney(clubMap, clubName);

    return 0;
}
