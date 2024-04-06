//SOLUTION USING LINKED LIST
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class node
{
    public:
    string club;
    float large,medium,small,bonus;
    node* next;
    node(string c,float l, float m, float s, float b)
    {
        club=c;
        large=l;
        medium=m;
        small=s;
        bonus=b;
        next=NULL;
    }
};

class ClubFundsDistribution {
public:
    node* head;
    int noofclubs;
    float fixed;
    float remaining;
    float sum;
    float *arr;

    ClubFundsDistribution() {
        head = NULL;
        noofclubs=0;
        fixed=0;
        remaining=0;
        sum=0;
        arr=NULL;
    }
    
    void addClub() {
         ifstream in("clubmoney.txt");
    string name,l,m,s,b;
    while(getline(in,name))
    {
        getline(in,l);
        float large=stof(l);
        getline(in,m);
        float medium=stof(m);
        getline(in,s);
        float small=stof(s);
        getline(in,b);
        float bonus=stof(b);
        node* newNode = new node(name, large, medium, small, bonus);
        if(head==NULL)
        {
           head=newNode;
        }
        else
        {
           node* temp=head;
           while(temp->next!=NULL)
              {
                 temp=temp->next;
              }
            temp->next=newNode;
        }
        noofclubs++;
    }
    in.close();
    }
    void distribute(float total)
    {
        fixed= total*(30.0/100);
        remaining=total-fixed;
        arr=new float[noofclubs];
        node* temp=head;
        for(int i=0;i<noofclubs;i++)
        {
            float priority=(5*temp->large)+(3*temp->medium)+(1.5*temp->small)+(0.5*temp->bonus);
            arr[i]=priority;
            sum=sum+priority;
            temp=temp->next;
        }
    }
    void calculate()
    {
        node* temp=head;
        for(int i=0;i<noofclubs;i++)
        {
            float moneyofclub=(fixed/noofclubs) + remaining*(arr[i]/sum);
            cout<<temp->club<<": "<<moneyofclub<<endl;
            temp=temp->next;
        }
    }
};
    
    int main()
    {
        ClubFundsDistribution a;
        a.addClub();
        int totalmoney;
        cout<<"ENTER THE TOTAL MONEY: "<<endl;
        cin>>totalmoney;
        a.distribute(totalmoney);
        a.calculate();
        return 0;
    }
