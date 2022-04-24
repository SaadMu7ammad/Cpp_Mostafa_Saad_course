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
  //enter number of names  then search by names by prefix 
  // not the optimal solution or not efficient but just using a new idea bu substr()
    // same idea in file >> Find_Full_names.cpp check'em 
    int q;
    cin>>q;
    vector <string>v;
    loop(0,q)
    {
        string name;
        cin>>name;
        v.push_back(name);
    }
    int trials;
    cin>>trials;
    while(trials--)
    {
        bool flag=false;
        string name;
        cin>>name;
        loop(0,q)
        {
            string tmp=v[i].substr(0,name.length());
            if(tmp==name)
            {
                cout<<v[i]<< " ";
                flag=true;
            }
        }
        if(flag==false)
        {
            cout<<"Not Found";
        }
        cout<<endl;
    }
    return 0;
}
