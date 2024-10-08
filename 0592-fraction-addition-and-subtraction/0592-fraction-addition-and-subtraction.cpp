class Solution {
    struct frac_t {
        int above;
        int below;
    };

    void getFracs(vector<frac_t> &fracs, string &expr) {
        int N = expr.length();
        int idx = 0;
        int sign = 1;

        frac_t frac;
        int digit = 0;
        while (idx < N) {
            if (isdigit(expr[idx])) {
                digit = digit * 10 + (expr[idx] - '0');
            }
            else if (expr[idx] == '/') {
                frac.above = sign * digit;
                digit = 0;
                sign = 1;
            }
            else {
                frac.below = sign * digit;
                fracs.push_back(frac);

                digit = 0;
                sign = expr[idx] == '+' ? 1 : -1;
            }

            ++idx;
        }

        /* Add last frac to fracs */
        frac.below = sign * digit;
        fracs.push_back(frac);
    }

    void addFrac(frac_t &result, frac_t toAdd) {
        if (result.below == 0) {
            result = toAdd;
            return ;
        }

        /* Get the least common multiple */
        int below_lcm = lcm(result.below, toAdd.below);
        result.above *= below_lcm / result.below;
        toAdd.above *= below_lcm / toAdd.below;

        /* Update result */
        result.above += toAdd.above;
        result.below = below_lcm;
    }

public:
    string fractionAddition(string expression) {
        vector<frac_t> fracs;
        getFracs(fracs, expression);

        /* Frac Addition */
        frac_t result(0, 0);
        for (frac_t frac : fracs) {
            addFrac(result, frac);
        }

        /* Simplify the result */
        if (result.above == 0) {
            return "0/1";
        }

        /* Greatest common divisor */ 
        int result_gcd = gcd(result.above, result.below);
        result.above /= result_gcd;
        result.below /= result_gcd;

        return to_string(result.above) + "/" + to_string(result.below);
    }
};