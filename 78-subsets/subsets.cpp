class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>subset;
        vector<int>set;
        createSubset(nums, 0, set, subset);
        return subset;
    }

    void createSubset(vector<int>&nums, int index, vector<int>&set,vector<vector<int>>&subset){
        if(index == nums.size()){
            subset.push_back(set);
            return;
        }
        set.push_back(nums[index]);
        createSubset(nums, index+1, set, subset);
        set.pop_back();
        createSubset(nums, index+1, set, subset);

    }
};