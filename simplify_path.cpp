class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
       stringstream ss(path);
       string token;
        while(getline(ss,token,'/'))
        {
            if(token=="" || token==".")
                continue;
            if(token==".." && !st.empty())
            {
                st.pop();
            }
            if(token!="..")
                st.push(token);
        }
        
        string ans="";
        while(!st.empty())
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        
        if(ans == "")
            return "/";
        else
            return ans;
    }
};
