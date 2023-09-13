class Solution {
public:
    void print(vector<int>& c){
        for(int i=0; i<c.size(); i++)
            cout<<c[i]<<",";
        cout<<endl;
    }
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> c(n, 1);

        for (int i=1; i<n; i++){
            if (ratings[i]>ratings[i-1]) 
                c[i]=c[i-1]+1;
        }
        for (int i=n-2; i>=0; i--)
            if (ratings[i]>ratings[i+1]) 
                c[i]=max(c[i], c[i+1]+1);
    //    print(c);
        return accumulate(c.begin(), c.begin()+n,0);
    }
};