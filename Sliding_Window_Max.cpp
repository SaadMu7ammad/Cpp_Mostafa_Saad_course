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
    int n;
    cin>>n;
    int arr[n];
    loop(0,n)cin>>arr[i];
    int k;
    cin>>k;
    multiset<int,greater<int>>st;  //sort the set from bigger to smaller
    loop(0,k)st.insert(arr[i]);
    cout<<*st.begin()<<" ";
    loop(k,n)
    {
         st.erase(arr[i-k]);  //erase the fist elemnt which is the bigger one to be ready to recieve a new elemnt 
        //st.erase(st.begin());
        st.insert(arr[i]);   //slide the window to the next elemnt in the array and add it to the set
        cout<<*st.begin()<<" ";  //print the fist elemnt( the max) 
    }
//inputs example
    //8
    // 1 3 -1 -3 5 3 6 7
    //3
    return 0;
}
