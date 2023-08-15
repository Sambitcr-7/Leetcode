//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int checkDivisible36(string S){
        // code here 
           int four_d=0, nine_d=0, sum=0;
       
       if(((S[S.size()-2]-'0')*10 + (S[S.size()-1]-'0'))%4==0) four_d=1; 
       
       for(int i=0; i<S.size(); i++)
        {
            sum+=S[i]-'0';
        }
       
        if(sum%9==0)nine_d=1;
        return four_d && nine_d;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.checkDivisible36(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends