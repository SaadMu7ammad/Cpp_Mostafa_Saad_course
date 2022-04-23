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
int prime(int num,int i=3)
{


    if(num==i)return 1;
    if(num==2)return 1;
    if(num<=1 || num%2 ==0)return 0;


    if(num % i ==0)return 0;
    return prime(num,++i);






}
int count_primes(int st,int en)
{

    if(prime(st))
    {

        if(st>en)return 0;

        return 1+count_primes(++st,en);
    }
    return count_primes(++st,en);


}

int main()
{

    fast();



    int start,endd;
    cin>>start>>endd;
    int res=count_primes(start,endd);
    cout<<"the num of primes from "<<start<<" to "<<endd<<" = "<<res;


    return 0;
}
