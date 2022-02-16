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

const int mxspec=20;
const int mx=5+1;
string names[mxspec][mx];
int Queue[mxspec] ; //such as frequency array to detect which specialization more than 5
int status[mxspec][mx] ; //we added +1 although the tot num is 20*5 to make a one extra space when we shift the whole array
// will see next
int tracker=0;




int menu()
{
    int choice =0;

    while(choice==0)
    {

        cout << "\nEnter your choice:\n";
        cout << "1) Add new patient\n";
        cout << "2) Print all patients\n";
        cout << "3) Get next patient\n";
        cout << "4) Exit\n";

        cin >> choice;

        if (choice>4 || choice<1)
        {
            cout << "Invalid choice. Try again\n";
            choice = 0;	// loop keep working
        }




    }

    return choice;


}
void shift_to_left(int specs,int mxqueue)
{

    for(int i =1; i<=mxqueue; i++)
    {


        names[specs][i-1]=names[specs][i];
        status[specs][i-1]=status[specs][i];

    }



}
void shift_to_right(int specs,int mxqueue)
{



    for(int i =mxqueue; i > 0; i--)
    {


        names[specs][i]=names[specs][i-1];
        status[specs][i]=status[specs][i-1];

    }







}

void system()
{





    while(true)
    {
        int choice=menu();
        if(choice==1)
        {
            int spec,stat;
            string name;
            cout<< "Enter specialization, name, status: ";

            cin>>spec>>name>>stat;



            if(Queue[spec]==5)
            {
               
                cout << "Sorry we can't add more patients for this specialization\n";

            }
            else if(stat==1)  //urgent so it must put first so we shift the whole array
            {

                shift_to_right(spec,Queue[spec]);
                Queue[spec]++;
                names[spec][0]=name;
                status[spec][0]=stat;
                

            }
            else if(stat==0)  //regular
            {

                int position=Queue[spec];


                names[spec][position]=name;
                status[spec][position]=stat;
                Queue[spec]++;
               
            }


        }

        else if(choice==2)
        {


            for(int i=0; i<mxspec; i++)
            {
                if(Queue[i])
                {
                    cout<<"There are "<<Queue[i]<<" patients in specialization "<<i<<"\n";

                    for(int j=0; j<Queue[i]; j++)
                    {

                       

                        cout<<names[i][j]<<" "<<status[i][j]<<"\n";


                    }
                }
            }
        }
        else if (choice==3)
        {
            cout<<"Enter Specialization num: ";
            int specialNum;
            cin>>specialNum;
            if(Queue[specialNum]==0)
            {



                cout<<"No patients at the moment , Have a rest :) \n";
            }
            else
            {
                Queue[specialNum]--;
                cout<<names[specialNum][0]<<" GO with the DR ,please\n";
                shift_to_left( specialNum,Queue[specialNum]);


            }




        }
        else if (choice==4)
        {

            cout<<" THE PROGRAM CLOSED \n";
            break;

        }


    }


}




int main()
{

    system();

    return 0;
}
