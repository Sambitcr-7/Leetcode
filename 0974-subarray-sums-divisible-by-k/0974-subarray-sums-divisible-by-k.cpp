class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        // approch-1 using 2 loops O(n2)
        // int sum=0;
        // int count=0;

        // for(int i=0;i<nums.size();i++){
        //     sum=0;
        //     for(int j=i;j<nums.size();j++){
        //         sum+=nums[j];
        //         if(sum%k==0)    count++;
        //     }
        // }
        // return count;




        // approch-2 O(n) maths+hash maps
        int sum=0;
        int count=0;
        
        unordered_map<int,int>m;//<remainder,frequency>
        m[0]=1;// this is done because initial cumulative sum = 0 and that sum%k will be equal to 0 always
        

        int rem;
        for(auto& x:nums){
            sum+=x;
            rem=sum%k;
            if(rem<0)   rem=k+rem;//catch for -ve remainder

            if(m.find(rem)!=m.end()){//exist
                count+=m[rem];
            }

            m[rem]++;
        }

        return count;
    }
};