// Derangement Problem, Similar to "Euler's wrong envelope" Problem
// But we might have duplicated chars, so the solution is Brutal Force DFS, plus early-backtracking

void helper(vector<int> nums, int begin, vector<vector<int>>& res, vector<int> & org)
{
    if(begin >= nums.size()-1)
    {
        res.push_back(nums);
        return;
    }
    
    for(int i = begin; i!= nums.size(); ++i)
    {
        if(nums[i] == nums[begin] && begin!=i) continue;
        if(nums[i] == org[begin]) continue;
        swap(nums[begin],nums[i]);
        helper(nums,begin+1,res,org);
    }
}

vector<vector<int>> permuteUnique(vector<int> nums) {
    vector<int> org = nums;
    sort(nums.begin(),nums.end());
    vector<vector<int>>  res;
    if (!nums.size()) return res;
    if(nums.size() == 1)
    {
        res.push_back(nums);
        return res;
    }
    else
        helper(nums,0,res, org);
    return res;
}
