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
add(int x,int y)
{

    cout<<x+y<<"\n";
}
sub(int x,int y)
{

    cout<<x-y<<"\n";
}
mut(int x,int y)
{

    cout<<x*y<<"\n";
}

divi(int x,int y)
{

    cout<<x/y<<"\n";
}
int menu()
{
    int choice = -1;
    while (choice == -1)
    {
        if (true)
        {
            cout << "\nMenu;\n";
            cout << "1) Add 2 numbers\n";
            cout << "2) Subtract 2 numbers\n";
            cout << "3) Multiply 2 numbers\n";
            cout << "4) Divide 2 numbers\n";
            cout << "5) Exit\n";
        }

        cout << "\nEnter your menu choice [1 - 5]: ";
        cin >> choice;
        if(choice==5)
        {


            cout << "exit ";
            break;

        }
        if (!(1 <= choice && choice <= 5))
        {
            cout << "Invalid choice. Try again\n";
            choice = -1;	// loop keep working
        }
        int xx,yy;
        cin>>xx>>yy;
        if(choice==1)
        {

            add(xx,yy);

        }
        if(choice==2)
        {

            sub(xx,yy);

        }
        if(choice==3)
        {


            mut(xx,yy);
        }
        if(choice==4)
        {


            divi(xx,yy);
        }


    }
    return choice;
}



int main()
{

    menu();






    return 0;
}
