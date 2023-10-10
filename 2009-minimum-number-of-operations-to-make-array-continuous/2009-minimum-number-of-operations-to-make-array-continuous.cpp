class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        //set for finding unique element 
        set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        vector<int>unique;
        for(int item:s){
            unique.push_back(item);
        }
        
        //sort the array(let unique.size= m  m*log(m))
        sort(unique.begin(),unique.end());
        
        int ans = INT_MAX;
        for(int i=0;i<unique.size();i++)
        {
            int start = unique[i];
            int last = start+n-1;
            
            //search for element just grater than last
            vector<int>::iterator upper=upper_bound(unique.begin(),unique.end(),last);
            int len = upper- unique.begin();
            ans = min(ans,n-(len-i));
            
        }
       return ans;
    }
};