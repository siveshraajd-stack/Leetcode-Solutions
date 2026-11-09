class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int maxEle = 0;
        
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] == 1){
                ans++;
            }
        else {
                maxEle = max(maxEle, ans);
                ans = 0;
            }
        }
        maxEle = max(maxEle, ans);
        return maxEle;
        
    }
};