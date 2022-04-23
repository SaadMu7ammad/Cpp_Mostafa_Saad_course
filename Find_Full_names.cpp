#include <bits/stdc++.h>
#define loop(start, n) for (int i = start; i < n; i++)
#define endl "\n"

typedef long long ll;
using namespace std;
void suiii()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
}
int main()
{
    cout<<"enter the num of  inputs : ";
    int q;
    cin>>q;
    map<string,vector<string>>mp;
    while(q--)
    {
        cout<<"enter the name parts ";
        int len;
        cin>>len;
        string full="";
        vector<string>v;
        cout<<"enter the name \n";
        loop(0,len)
        {
            string name ;
            cin>>name;
            full+=name;
            v.push_back(full);
        }
        for(auto x: v)
        {
            mp[x].push_back(full);
        }
    }
    cout<<"enter the name of queries search ";
    int n;
    cin>>n;
    while(n--)
    {
        cout<<"length  ";
        int lenn ;
        cin>>lenn;
        cout<<"enter the name u search :\n";
        string f_name="";
        loop(0,lenn)
        {
            string namee;
            cin>>namee;
            f_name+=namee;
        }
        if(mp.count(f_name))
        {
            for(auto x: mp[f_name])
            {
                cout<<x<<endl;
            }
        }
        else
        {
            cout<<"not found"<<endl;
        }
    }
    return 0;
}
