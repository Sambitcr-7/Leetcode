class Solution {
public:
    string destCity(vector<vector<string>>& paths) 
    {
        int i,j;
        map<string,string> mp;
        
        //Storing all the paths in a map
        for(i=0;i<paths.size();i++)
        {
            mp[paths[i][0]] = paths[i][1];
        }
        
		//map iterator
        map<string,string> :: iterator it;
        it=mp.begin();
        string s=it->second;
        
        //Search until you reach the destination city
        while(mp.find(s)!=mp.end())
        {
            s=mp[s];
            
        }
        
		//return destination
        return s;
    }
};
