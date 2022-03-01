#include <iostream>
#include <algorithm>
//#include<bits/stdc++.h>
#define loop(n) for(int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

const int mxspec = 20;
const int mx = 5 + 1;

struct hospital
{
    int len = 0;
    string names[mxspec];

    int status[mxspec]; //we added +1 although the tot num is 20*5 to make a one extra space when we shift the whole array
    // will see next
    int tracker = 0;

    void shift_to_left(int specs )
    {
        for (int i = 1; i <= len; i++)
        {
            names[i - 1] = names[i];
            status[i - 1] = status[i];
        }
    }


    void shift_to_right()
    {
        for (int i =len ; i > 0; i--)
        {
            names[i] = names[i - 1];
            status[i] = status[i - 1];
        }
    }

};


int menu()
{
    int choice = 0;

    while (choice == 0)
    {

        cout << "\nEnter your choice:\n";
        cout << "1) Add new patient\n";
        cout << "2) Print all patients\n";
        cout << "3) Get next patient\n";
        cout << "4) Exit\n";

        cin >> choice;

        if (choice > 4 || choice < 1)
        {
            cout << "Invalid choice. Try again\n";
            choice = 0;	// loop keep working
        }
    }
    return choice;
}



struct hospitalSystem
{
    hospital Queue[mxspec]; //such as frequency array to detect which specialization more than 5

    void system()
    {
        while (true)
        {
            int choice = menu();


            if (choice == 1)
            {
                int spec, stat;
                string name;
                cout << "Enter specialization, name, status: ";

                cin >> spec >> name >> stat;

                if (Queue[spec].len== 5)
                {

                    cout << "Sorry we can't add more patients for this specialization\n";

                }
                else if (stat == 1)  //urgent so it must put first so we shift the whole array
                {

                    Queue[spec].shift_to_right();
                    Queue[spec].len++;
                    Queue[spec].names[0] = name;
                    Queue[spec].status[0] = stat;

                }
                else if (stat == 0)  //regular
                {

                    int position = Queue[spec].len;

                    Queue[spec].names[position] = name;
                    Queue[spec].status[position] = stat;
                    Queue[spec].len++;

                }

            }

            else if (choice == 2)
            {

                display();
            }

            else if (choice == 3)
            {
                cout << "Enter Specialization num: ";
                int specialNum;
                cin >> specialNum;
                if (Queue[specialNum] .len== 0)
                {
                    cout << "No patients at the moment , Have a rest :) \n";
                }
                else
                {
                    Queue[specialNum].len--;
                    cout << Queue[specialNum].names[0] << " GO with the DR ,please\n";
                 Queue[specialNum].shift_to_left(specialNum);
                }
            }

            else if (choice == 4)
            {
                cout << " THE PROGRAM CLOSED \n";
                break;

            }
        }


    }

    void display()
    {
        for (int i = 0; i < mxspec; i++)
        {
            if (Queue[i].len >0)
            {
                cout << "There are " << Queue[i].len << " patients in specialization " << i << "\n";

                for (int j = 0; j < Queue[i].len; j++)
                {
                    cout << Queue[i].names[j] << " ";


                    if (Queue[i].status[j] == 0) {
                        cout << "Regular" << "\n";;
                    }
                    else {

                        cout << "Urgent" << "\n";;
                    }
                }
            }
        }
    }
};




int main()
{
    hospitalSystem obj ;

    obj.system();
    

    return 0;
}
