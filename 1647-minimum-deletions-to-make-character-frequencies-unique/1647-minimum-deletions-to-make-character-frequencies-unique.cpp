class Solution {
public:
    int minDeletions(string s) {
                // store frequencys of every character
        unordered_map<char,int> hmap;
        for(char c : s) hmap[c]++;

        // used frequencys set
        unordered_set<int> used;

        int deletions = 0;  // counter of how many deletions we need to do

        // iterate through hmap
        for(auto& [c, freq] : hmap) {

            // decrement untill we find a unused frequency or it becomes -
            while(used.count(freq) && freq > 0) {
                deletions++; // increment deletions
                freq--; // decrement frequency of this character since we are removing one
            }
            // insert this valid frequency
            if(freq > 0)used.insert(freq);
        }

        return deletions;

    }
};