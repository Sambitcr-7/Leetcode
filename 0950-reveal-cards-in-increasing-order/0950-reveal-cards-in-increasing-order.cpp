class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
          sort(deck.begin(),deck.end());
        queue<int>q;
        vector<int>temp(deck.size(),0);
        for(int i=0;i<deck.size();i++)
        {
            q.push(i);
        }
        int i=0;
        while(!q.empty())
        {
            int t=q.front();
            temp[t]=deck[i];
            i++;
            q.pop();
            if(!q.empty())
            {
                int p=q.front();
                q.pop();
                q.push(p);
            }
        }
        return temp;
    }
};