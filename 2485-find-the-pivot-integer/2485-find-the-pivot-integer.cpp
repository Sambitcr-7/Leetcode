class Solution {
public:
    int presum(int n){
        return (n * (n + 1))/ 2;
    }
    int pivotInteger(int n) {
        int low = 0;
        int high = n-1;
        if(n == 1)return 1;
        int k = presum(n);
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(mid > 0 and presum(mid+1) == (k - presum(mid))){
                return mid + 1;
            }
            else if(mid > 0 and presum(mid+1) < (k - presum(mid))){
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return -1;
    }
};