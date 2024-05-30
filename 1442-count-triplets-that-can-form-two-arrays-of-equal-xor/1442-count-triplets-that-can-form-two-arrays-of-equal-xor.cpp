class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int summ = arr[i];
            for (int k = i + 1; k < n; k++) {
                summ ^= arr[k];

                if (summ == 0) {
                    count += (k - i);
                }
            }
        }

        return count;
    }
};