static int __star = []{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL),cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    int minDays(vector<int>& v, int m, int k) {
        if(m>v.size()/k) return -1;
        int l=1,h=1e9;
        while(l<h)
        {
            int mid=(l+h)/2;
            int n=0,c=0;
            for(auto &i:v)
            {
                if(i<=mid) c++;
                else c=0;
                if(c==k) n++,c=0;
            }
            if(n>=m) h=mid;
            else l=mid+1;
        }
        return l;
    }
};