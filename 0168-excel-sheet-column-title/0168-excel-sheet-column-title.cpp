class Solution {
public:
    string convertToTitle(int columnNumber) {
         string ans = "";
        while (columnNumber > 0) {
            int rem = (columnNumber - 1) % 26;  // Find rem after dividing total charactor
            char l='A'+rem; // last charctor in string
            ans = l + ans; // add the remainder in the resulut.    
            columnNumber = (columnNumber - 1) / 26; // Update 
        }
        return ans;
    }
};