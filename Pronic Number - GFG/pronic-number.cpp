//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> pronicNumbers(int N)
    {
        // Write Your Code here
          vector<int> res;
       int i=0;
       int j=1;
       while(1)
       {
           int prod = i*j;
           if(prod <= N)
               res.push_back(prod);
           else
               break;
           i++;
           j++;
       }
       return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        
        vector<int> ans = ob.pronicNumbers(N);
        for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends