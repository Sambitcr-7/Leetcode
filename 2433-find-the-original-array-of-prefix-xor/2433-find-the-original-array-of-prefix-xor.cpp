class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
         vector<int> arr;
        // a^b= c : a^b^a= c^a : b= c^a
        int a= 0,ln= pref.size();
        for(int i=0;i<ln;i++){
            arr.push_back(pref[i]^a);
            a^= arr.back();
        }
        return arr;
    }
};