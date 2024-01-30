class Solution {
public:
    int func(stack<int>&st, string op){
        int op1 = st.top();st.pop();
        int op2 = st.top();st.pop();

        if(op=="+") return op1+op2;
        if(op=="-") return op2-op1;
        if(op=="/") return op2/op1;
        if(op=="*") return op1*op2;

        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string it:tokens){
            if(it=="+" || it=="-" || it=="/" || it=="*"){
                st.push(func(st,it));
            }
            else{
                int num = stoi(it);
                st.push(num);
            }
        }
        return st.top();
    }
};