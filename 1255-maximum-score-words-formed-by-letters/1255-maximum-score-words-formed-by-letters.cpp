class Solution {
public:

    void solve(vector<string> & words, int i, vector<string> &temp, vector<vector<string>> &ans)
    {
        if(i >= words.size())
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back(words[i]);
        solve(words, i+1, temp, ans);

        temp.pop_back();
        solve(words, i+1, temp, ans);
    }
    
    int findScore(string str, vector<int> scores)
    {
        int score = 0;
        for(int i = 0; i < str.length(); i++)
        {
            int s = int(str[i]);
            score += scores[s - 97];
        }
        return score;
    }
    
    bool check(vector<string> words, vector<char> letters)
    {
        unordered_map<char, int> mp_letters;
        unordered_map<char, int> mp_words;
        
        for(auto it : letters)
        {
            mp_letters[it]++;
        }
        
        for(auto it : words)
        {
            for(auto i : it)
                mp_words[i]++;
        }
        
        for(auto it : mp_words)
        {
            if(mp_letters.find(it.first) != mp_letters.end())
            {
                if(it.second > mp_letters[it.first])
                    return false;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<string> temp;
        vector<vector<string>> ans;
        
        solve(words, 0, temp, ans);
        
        int word_score = 0;
        int max_score = INT_MIN;
        
        for(auto it : ans)
        {
            word_score = 0;
            if(check(it, letters))
            {
                for(auto i : it)
                {
                    word_score += findScore(i, score);
                }
                max_score = max(max_score, word_score);
            }
        }
        return max_score;
    }
};