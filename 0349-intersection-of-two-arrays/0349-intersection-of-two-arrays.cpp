class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
         sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i=0, j=0;
        set<int> st;
        vector<int> ans;
        int n = min(nums1.size(), nums2.size());

        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j] ){
                j++;
            }
            else{
                st.insert(nums1[i]);
                i++;
                j++;
            }
        }
        for(auto elem: st){
            ans.push_back(elem);
        }
        return ans; 
    }
};