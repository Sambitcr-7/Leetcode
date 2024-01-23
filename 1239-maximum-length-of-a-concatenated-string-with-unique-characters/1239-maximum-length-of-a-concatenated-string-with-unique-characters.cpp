class Solution {
public:
    // IDEA: create a bitmask for unique characters and store them with a count of set bits. Iterate over all possible
    //       combinations of strings and check that they have no characters in common. Take the maximum of these.
	//       Reduce each string to a bitmask that we can compare in O(1).
    // Edge cases: A string may have duplicate characters itself, flag these and then skip any combination that includes this.
	// Time Complexity: O(n*2^n)
	// Space Complexity: O(n)
    int maxLength(vector<string>& arr) {
      int res = 0, n = arr.size();
      using uint = unsigned int;
      using Count = pair<uint, int>;
      vector<Count> masks(n);
      
      for (int i = 0; i < n; i++) {
        for (char c : arr[i]) {
          masks[i].first |= (1 << (c - 'a')); // Set corresponding bit in the bitmask, a->0, b->1, ...
        }
        int cnt = __builtin_popcount(masks[i].first); // count the set bits of the mask
        masks[i].second = cnt < arr[i].length() ? -1 : cnt; // cnt must be same as length of string, invalid (duplicate characters) strings have value -1
      }
      
      int allones = (1 << n) - 1; // bitmask of length n
      vector<uint> combs; // use this to recover the subsequence 
      for (int i = 1; i <= allones; i++) { // loop over all combinations (set bits in i mean that we are using that entry of arr - bit index)
        Count m{0,0};
        bool skip = false;
        for (int j = 0; j < n; j++) {
          if (((1 << j) & i) == 0) continue; // this index is not part of the combination
          if (masks[j].second == -1 || (m.first & masks[j].first)) {
            skip = true;
            break; // combination contains at least 1 duplicate character
          }
          m.first  |= masks[j].first;
          m.second += masks[j].second;
        }        
        if (!skip) { // we have found a subsequence that doesn't contain any duplicate characters
          if (res < m.second) { 
            res = m.second;
            combs.clear(); // new longest means we need to clear out all previous combinations
            combs.push_back(i);
          } else if (res == m.second) {
            combs.push_back(i); // add to our list of combinations with the current max length
          }
        }
      }
      
      // Only if you want to see all the possible subsequences with maximum length
      for (auto comb : combs) {
        string subsequence;
        for (int i = 0; i < n; i++) {
          if (comb & (1 << i))
            subsequence += arr[i];
        }
        cout << subsequence << endl;
      }
      
      return res;
    }
};