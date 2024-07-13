class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string dir) {
        vector<vector<int>> vec; int n= pos.size();
        for(int i=0; i<n; i++){
            int health= (dir[i]=='R') ? h[i] : (-1)*h[i]; // Sign represent direction. If direction is 'L' , make health -ve (same as asteroid collision) 
			// as we need to return answer in the order they were given in the input, so we will carry the actual index throughout.
            vec.push_back({pos[i], health, i});  // {position, health, actualIndex}
        }
        
        sort(vec.begin(), vec.end()); // sort them in the order of their positions
        stack<vector<int>> stk; // {health, actualIndex}
        
        for(int i=0; i<vec.size(); i++){
            int health= vec[i][1]; int idx= vec[i][2]; 
            if(stk.empty()){ // If stack is empty, simply push it
                stk.push({health, idx});
            }
            else if(stk.top()[0]>0 && health<0){ // opposite moving (towards each other) --> Collission
                while(!stk.empty() && (stk.top()[0]>0 && health<0) && stk.top()[0] < (abs)(health)){
					// run loop till currentHealth is greater in magnitude than stack top [as it will destroy stack top, so pop it]
                    stk.pop();
                    health++; // also after collision, currentHealth will decreament by one ( as health <0, so decreament means ++)
                }
                if(!stk.empty() && stk.top()[0]==(abs)(health)){  // stack top == currentHealth --> Both will collide and destroy each other
					// pop top and ignore health (desttoy both top and health)
                    stk.pop(); continue;
                }
                else if(!stk.empty() && stk.top()[0] > (abs)(health)){  // stack top  > currHealth, they will collide and stack top decreaments
					// reduce top value by 1 and destroy health
                    int top= stk.top()[0]; int i= stk.top()[1]; stk.pop(); top--;
                    stk.push({top, i});
                    continue;
                }
                stk.push({health, idx}); // if all above conditions fails, then currentHealth can be safely pushed into stack
            }
            else if(stk.top()[0]>0 && health>0 || stk.top()[0]<0 && health<0){ // top and health are in same direction --> No collision
                stk.push({health, idx});
            }
            else if(stk.top()[0]<0 && health>0){ // they are moving in opposite direction (away) --> No collision 
                stk.push({health, idx});
            }
        }
        vector<vector<int>> temp;  // { actualIndex of remaining Health, remaining healths }
        while(!stk.empty()){
            temp.push_back({stk.top()[1], stk.top()[0]}); stk.pop();
        }
        
        sort(temp.begin(), temp.end()); // sort in increasing order of actualIndex [as we need to return answer in the order they were given in the input]
        vector<int> ans;
        for(int i=0; i<temp.size(); i++){
            ans.push_back((abs)(temp[i][1])); // take absolute value of health as it can be <0 
        }
        return ans; // finalAnswer
    }
};