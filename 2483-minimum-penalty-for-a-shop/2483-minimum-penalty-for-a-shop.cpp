class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> nn(n+1, 0), p(n+1, 0);
        int y_rem = 0;
        
        nn[0] = (customers[0]=='N');
        y_rem = (customers[0]=='Y');
        
        for (int i = 1; i <= n; i++) {
            nn[i]=nn[i-1]+(customers[i-1]=='N'); 
            y_rem+=(customers[i-1]=='Y'); 
        }
        
        p[0] = nn[0]+y_rem;
        int minP=p[0], minI=0;
        
        for (int i = 1; i <= n; i++) {
            y_rem -= (customers[i-1] == 'Y');
            p[i]=nn[i] + y_rem;
            
            if (minP> p[i]) {
                minP=p[i];
                minI=i;
            }
        }
        return minI;
    }
};
