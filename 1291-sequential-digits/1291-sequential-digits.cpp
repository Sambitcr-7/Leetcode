class Solution {
public:
    bool check(int low, int high, int num){
        if(low<=num && high>=num)  return 1;
        return 0;
    }
    vector<int> sequentialDigits(int low, int high) {
        int low_digit_cnt = log10(low) + 1;
        int high_digit_cnt = log10(high) + 1;

        vector<int> ans;
        for(int i=low_digit_cnt; i<=high_digit_cnt; i++){
            for(char x = '1'; x<='9'-i+1; x++){
                string num;
                char y = x;
                for(int j = 0; j<i; y++, j++){
                    num += y;
                }
                int number = stoi(num);
                if(check(low, high, number)){
                    ans.push_back(number);
                }
            }
        }
        return ans;
    }
};