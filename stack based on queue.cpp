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
struct st
{
    queue<int>q;
    void push(int x)
    {
        int sizee=q.size();
        q.push(x);
        while(sizee--)
        {
            q.push(q.front());    // 1 2 3 4  if we push 6
            // this block will do this
            //6 added from the back
            ///   back of the q>>   6 1 2 3 4   <<front of the q
            /// 4 6 1 2 3
            /// 3 4 6 1 2
            /// 2 3 4 6 1
            /// 1 2 3 4 6  now 6 is on the front like a stack that it pushed and become on the top
            q.pop();
        }
    }
    void pop()
    {
        if(!q.empty())
            q.pop();
    }
    int top()
    {
        return q.front();
    }
    bool empty()
    {
        if(q.empty())return true;
        else return false;
    }
};
int main()
{
    st obj;
    obj.push(5);
    obj.push(6);
    obj.push(7);
    obj.push(9);
    obj.push(11);

    obj.pop();

    while(!obj.empty())
    {
        cout<<obj.top()<<" ";
        obj.pop();
    }
    return 0;
}
