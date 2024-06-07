/* Adapted my Trie implementation from Leetcode 208.
 * If you want to solve this question efficiently, watch
 * Youtube videos for the Trie data structure and solve
 * Leetcode 208. 
 *
 * Check out my Leetcode 208 Implement Trie (Prefix Tree)
 * Solution here: https://leetcode.com/problems/implement-trie-prefix-tree/solutions/5271799/c-implementation-array-vs-unordered-map-both-solutions-easy-to-understand
 *
 *
 * Trie Implementation below.
 */

const size_t NUM_LETTERS = 26;

class Trie {
private:
    struct TrieNode {
        bool isEnd = false;
        TrieNode* next[NUM_LETTERS] = {nullptr};
    };

    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}
    
    /* Insert into the Trie */
    void insert(string word) {
        TrieNode* current = root;

        int idx;
        for (char c : word) {
            idx = c - 'a';
            if (!current->next[idx]) {
                current->next[idx] = new TrieNode();
            }
            current = current->next[idx];
        }
        current->isEnd = true;
    }

    /* New replace_word method */
    string replace_word(string word) {
        TrieNode* current = root;
        string new_word = ""; // To store the returned word
        int idx;

        for (char c : word) {
            idx = c - 'a';
            current = current->next[idx];

            if (!current) { // If next char does not exist (and haven't returned yet) no prefix
                return word;
            }

            new_word.push_back(c); // Add next char to new_word
            
            if (current->isEnd) { // If the current Node is an end node, return new_word
                return new_word;
            }
        }

        // all chars of word processed.
        // no prefix in trie despite all chars existing. push original word.
        return word;
    }
};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        std::string ans = "";
        
        Trie t;

        // Push all dict items into the Trie
        for (const string &s : dictionary) {
            t.insert(s);
        }

        // Strinstream processing to get rid of whitespace
        std::stringstream ss(sentence);
        std::string word;

        while (ss >> word) {
            // Call replace word and push_back
            ans += t.replace_word(word);
            ans.push_back(' ');
        }

        // need pop_back() to get rid of extra ' ' at the end.
        ans.pop_back(); // Works because there's at least 1 word in the input.
        return ans;
    }
};
