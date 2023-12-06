class Solution {
public:
    int totalMoney(int n) {
        // calculate the money for the fully weeks
        int weeks = n / 7;
        int moneyFirstWeek = (1 + 7) * 7 / 2;
        int moneyLastWeek = (weeks + 3) * 7;
        int moneyWeeks = (moneyFirstWeek + moneyLastWeek) * weeks / 2;

        // calculate the money for the rest (days)
        int days = n % 7;
        int moneyMonday = (weeks + 1);
        int moneyLastDay = (weeks + 1 + days - 1);
        int moneyDays = (moneyMonday + moneyLastDay) * days / 2;

        return (moneyWeeks + moneyDays);
    }
};