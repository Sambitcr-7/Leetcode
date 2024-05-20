class Solution {
    vector<int> v;
public:
    void func(vector<int> &nums,int i,int &sum){
        if(i>=nums.size()){
            int x_or=0;
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
                x_or = x_or ^ v[i];
            }
            sum+=x_or;
            cout<<endl;
            return;
        }
        v.push_back(nums[i]);
        func(nums,i+1,sum);
        v.pop_back();
        func(nums,i+1,sum);
    }
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        
        func(nums,0,sum);
        return sum;
    }
};
