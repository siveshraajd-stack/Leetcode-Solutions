class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            long long product = 1;
            long long lcm = 1;
            int g = 0;

            for (int j = i; j < nums.size(); j++) {
                g = gcd(g, nums[j]);

                lcm = (lcm / gcd(lcm, (long long)nums[j])) * nums[j];

                if (product > (long long)1e18 / nums[j])
                    break;

                product *= nums[j];

                if (product == (long long)g * lcm) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};