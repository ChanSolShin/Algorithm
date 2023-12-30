#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    int n;
    string order;
    int flag;
    deque <int> dq;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>order;
        if(order=="push_front")
        {
            cin>>flag;
            dq.push_front(flag);
        }
        else if(order=="push_back")
        {
            cin>>flag;
            dq.push_back(flag);
        }
        else if(order=="pop_front")
        {
            if(dq.empty())
                cout<<"-1"<<endl;
            else
            {
                int qwe=dq.front();
            dq.pop_front();
            cout<<qwe<<endl;
            }}
        else if(order=="pop_back")
        {
            if(dq.empty())
                cout<<"-1"<<endl;
            else
            {
            int qwe=dq.back();
            dq.pop_back();
            cout<<qwe<<endl;
            }}
        else if(order=="size")
        {
            cout<<dq.size()<<endl;
        }
        else if(order=="empty")
        {
            cout<<dq.empty()<<endl;
        }
        else if(order=="front")
        {
            if(dq.empty())
                cout<<"-1"<<endl;
            else
            cout<<dq.front()<<endl;
        }
        else if(order=="back")
        {
            if(dq.empty())
                cout<<"-1";
            else
            cout<<dq.back()<<endl;
        }
    }
}
