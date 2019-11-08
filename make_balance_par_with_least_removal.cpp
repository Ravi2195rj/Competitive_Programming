/*
Input :
6
ab(a(c)fg)9)
)a(b)c()(
)(
a(b))
(a(c()b)
(a)b(c)d(e)f)(g)

Output : 
ab(a(c)fg)9  or ab(a(c)fg9)
a(b)c()

a(b)
a(c()b)      or (ac()b)      or  (a(c)b)
(a)b(c)d(e)f(g)

*/


#include<bits/stdc++.h>
using namespace std;
string getBalanceParenthesisString(string s)
{
    int len = s.length();
    stack<int> st;
    vector<int> flag(len,1); // mark each character as valid & balance.. 
    // When Traverse the string , When Invalid bracket encounter mark that index as false(Not included into result)
    for(int i=0;i<len;i++)
    {
        if(s[i]=='(')
            st.push(i);

        else if(s[i]==')')
        {
            if(st.empty())
                flag[i]=0;
            else
                st.pop();
        }
        else // character a,b,c just continue
        {
            continue;
        }
        
    }
    while(!st.empty())
    {
        flag[st.top()]=0;
        st.pop();
    }

    string ans="";
    for(int i=0;i<len;i++)
    {
        if(flag[i])
            ans += s[i];
    }
    return ans;

}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        string s;
        cin>>s;
        cout<<getBalanceParenthesisString(s)<<endl;
    }
    return 0;
}


