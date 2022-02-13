#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
#define loop(n) for(int i = 0; i < n; i++)

typedef long long ll;



using namespace std;

void fast()
{


    cin.tie(0);
    cin.sync_with_stdio(0);
}
const int MAX = 10000;

string names[MAX];
int ages[MAX];
double salaries[MAX];
char genders[MAX];
int added = 0;
int choice=-1;
void choose_one()
{


    cout << "Enter name: ";
    cin >> names[added];

    cout << "Enter age: ";
    cin >> ages[added];

    cout << "Enter salary: ";
    cin >> salaries[added];

    cout << "Enter gender (M/F): ";
    cin >> genders[added];
    ++added;

    choice=-1;


}
void choose_two()
{
    bool flag=false;
    cout << "****************************\n";
    for (int i = 0; i < added; ++i)
    {
        if (ages[i] != -1 )
        {
            cout << names[i] << " " << ages[i] << " " << salaries[i]
                 << " " << genders[i] << "\n";
            flag=true;
        }
    }
    if(!flag)
    {
        cout<<"NOT FOUND \n";
    }
}


void choose_three()
{
    cout << "Enter start and end age: ";
    int start, end;
    cin >> start >> end;

    for (int i = 0; i < added; ++i)
    {
        if (start <= ages[i] && ages[i] <= end)
            ages[i] = -1;// Let's mark a removed entry with -1 (lazy delete)
    }
}

void choose_four()
{
    cout << "Enter the name and salary: ";
    string name;
    int salary;
    cin >> name >> salary;

    bool is_found = false;
    for (int i = 0; i < added; ++i)
    {
        if (ages[i] != -1 && names[i] == name)
        {
            is_found = true;
            salaries[i] = salary;
            break;
        }
    }
    if (!is_found)
        cout << "No employee with this name!\n";
}

void display(int choose)
{
    while(1)
    {

        if(choose==1)
        {

            choose_one();

        }
        else if (choose==2)
        {


            choose_two();

        }
        else if (choose==3)
        {

            choose_three();

        }
        else if (choose==4)
        {

            choose_four();

        }
        else if (!(1 <= choose && choose <= 4))
        {
            cout << "Invalid choice. Try again\n";
            continue;
        }


        cout << "\nEnter your choice:\n";
        cout << "1) Add new employee\n";
        cout << "2) Print all employees\n";
        cout << "3) Delete by age\n";
        cout << "4) Update Salary by name\n";
        cin>>choose;

    }
}

int main()
{


    const int MAX = 10000;

    string names[MAX];
    int ages[MAX];
    double salaries[MAX];
    char genders[MAX];
    int added = 0;	// Number of employees



    cout << "\nEnter your choice:\n";
    cout << "1) Add new employee\n";
    cout << "2) Print all employees\n";
    cout << "3) Delete by age\n";
    cout << "4) Update Salary by name\n";

    while(1)
    {
        cin >> choice;
        display(choice);
    }
    //if (cin.fail())			break;




    return 0;
}
