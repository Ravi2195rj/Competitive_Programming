class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) //skip same sequence,
                continue;
            
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(j > i + 1 && nums[j] == nums[j-1]) // skip same sequence
                    continue;
                
                int tar = target - nums[i] - nums[j];
                int k = j + 1;
                int l = nums.size() - 1;
                while(k < l)
                {
                    if(nums[k] + nums[l] == tar)
                    {
                        res.push_back({nums[i],nums[j],nums[k],nums[l]});
                        while(k < l && nums[k] == nums[k+1]) k++;
                        while(k < l && nums[l] == nums[l-1]) l--;
                        k++;
                        l--;
                    }
                    else if(nums[k] + nums[l] > tar){
                        l--;
                    }
                    else
                        k++;
                }
            }
        }
        return res;
    }
};
