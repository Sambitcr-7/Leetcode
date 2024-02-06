class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string, vector<string>> anagram_map;
        
        // Iterate through each string in the input vector
        for (string& s : strs) {
            // Sort the string to identify its anagram signature
            string sorted_str = s;
            sort(sorted_str.begin(), sorted_str.end());
            
            // Add the sorted string to the anagram map and append
            // the original string to the corresponding anagram vector
            anagram_map[sorted_str].push_back(s);
        }
        
        // Create a vector to store the grouped anagrams
        vector<vector<string>> grouped_anagrams;
        
        // Iterate through the values of the anagram map
        for (auto& pair : anagram_map) {
            // Add the vector of anagrams to the grouped anagrams vector
            grouped_anagrams.push_back(pair.second);
        }
        
        return grouped_anagrams;
    }
};