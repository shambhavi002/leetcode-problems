
class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& ds,
               vector<bool>& freq) {

        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (freq[i])
                continue;

            // Skip duplicate elements at the same level
            if (i > 0 && nums[i] == nums[i - 1] && !freq[i - 1])
                continue;

            freq[i] = true;
            ds.push_back(nums[i]);

            solve(nums, ds, freq);

            // Backtracking
            ds.pop_back();
            freq[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> ds;
        vector<bool> freq(nums.size(), false);

        solve(nums, ds, freq);

        return ans;
    }
};
