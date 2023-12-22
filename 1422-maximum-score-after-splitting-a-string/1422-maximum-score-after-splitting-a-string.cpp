class Solution {
public:
    // Function to count the number of 0s before index i and 1s from index i onwards
    int check(int i, string &s ){
        int zero=0,once=0;
        
        // Count 0s before index i
        for(int j =0;j<i;j++){
            if(s[j]=='0') zero++;
        }
        
        // Count 1s from index i onwards
        for(int j =i;j<s.size();j++){
            if(s[j]=='1') once++;
        }
        
        // Return the sum of 0s and 1s
        return zero + once;
    }
    
    // Function to find the maximum score
    int maxScore(string s) {
        int ans=0;
        
        // Loop through the string except the first and last characters
        for(int i =1;i<s.size();i++){
            // Update ans with the maximum score obtained by check() function
            ans = max(ans,check(i,s));
        }
        
        // Return the maximum score
        return ans;
    }
};
