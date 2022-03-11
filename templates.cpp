#include<bits/stdc++.h>
#define loop(n) for(int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

void suiii()
{


    cin.tie(0);
    cin.sync_with_stdio(0);
}

template<typename x>
x maxi(x a,x b)
{

    if(a>b)return a;

    return b;


}


template<typename x,typename y>
y mini(x one,y two)
{

    if(one>two)return two;

    return one;


}



template<>
string mini(string one,string two)
{

    return "invalid operation";

}
int main()
{

    cout<<maxi(2,5);
    cout<<"\n---------------\n";

    cout<<mini(19.9,2.10);
    cout<<"\n---------------\n";

    cout<<mini((string)"saf",(string)"asff");
    return 0;
}
