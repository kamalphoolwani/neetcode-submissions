class Solution {
    int eval(int a, int b, string expr){
        if(expr == "+")
            return a+b;
        else if(expr == "-")
            return b - a;
        else if(expr == "*")
            return a*b;
        return b/a;
        
    }
public:
    int evalRPN(vector<string>& tokens) {
        int n  =  tokens.size();
        stack<int> st;
        int ans;

        for(int i = 0; i<n; i++){
            if(!st.empty() and (tokens[i] == "+" ||tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int ans = eval(a, b, tokens[i]);
                st.push(ans);
            }
            else
                st.push(stoi(tokens[i]));
        }

        return st.top();
    
    }
};
