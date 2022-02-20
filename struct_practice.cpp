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

int add=0;
int arr[1000] ;
struct Queue
{


    void add_end(int value)
    {

        arr[add]=value;
        ++add;
    }


    void add_front(int value)
    {


        for(int i=0; i<add; i++)
        {

            arr[add-i]=arr[add-i-1];


        }
        ++add;
        arr[0]=value;

    }


    int remove_front( )
    {


        loop(add)
        {
            if(i<4)
                arr[i]=arr[i+1];

        }
        if(add!=0)--add;




    }
    void print()
    {
        loop(add)
        cout<<arr[i]<<" ";

        cout<<endl;
    }
};

int main()
{
    Queue obj;

    int x;
    cin>>x;

    obj.add_front(x);


    int z;
    cin>>z;
    obj.add_front(z);

    obj.remove_front();

    obj.print();

    int y;
    cin>>y;

    obj.add_end(y);




    obj.print();
    return 0;
}
