// O(n) time O(n) space
vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int n = (int)nums.size();
        for (int i = 0; i < n; i++) {
            auto p = map.find(target-nums[i]);
            if (p!=map.end()) {
                return {p->second+1, i+1};
            }
            map[nums[i]]=i;
        }
    }
    
// O(nlogn) time O(1) space
vector<int> twoSumNlogN(vector<int> &numbers, int target) {
	vector<int> tmp = numbers;
	sort(tmp.begin(), tmp.end());
	int l = 0, r = (int) tmp.size() - 1;
	while (l < r) {
		int mid = tmp[l] + tmp[r];
		if (mid == target) break;
		if (mid < target) ++l; else --r;
	}
	
	int index1 = 0, index2 = 0;
	for (int i = 0; i < tmp.size(); ++i) {
		if (numbers[i] == tmp[l]) { index1 = i; break; }
	}
	for (int i = (int)tmp.size() - 1; i >= 0; --i) {
		if (numbers[i] == tmp[r]) { index2 = i; break; }
	}
	
	if (index1 > index2) { index1 ^= index2; index2 ^= index1; index1 ^= index2;  }
	vector<int> result {index1 + 1, index2 + 1};
	return result;
}
