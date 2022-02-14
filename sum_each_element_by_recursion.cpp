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
void arr_sum(int arr[],int len)
{


    if(len==0)
    {
        return ;
    }



    

    arr_sum(arr,len-1);

    arr[len-1]+=((arr[len-1])*(arr[len-1]-1))/2;
}


int main()
{

    fast();

    int arr[]= {1,8,2,10,3};
    arr_sum(arr,5);
    loop(5)
    {

        cout<<arr[i]<<" ";
    }

    return 0;
}
