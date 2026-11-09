class Solution {
public:
    void solve(vector<int>& nums, int start,
               vector<int>& curr, vector<vector<int>>& ans) {

        ans.push_back(curr);

        for (int i = start; i < nums.size(); i++) {

            // Skip duplicate choices at the same level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            curr.push_back(nums[i]);

            solve(nums, i + 1, curr, ans);

            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> curr;

        solve(nums, 0, curr, ans);

        return ans;
    }
};