// this one is medium oh my god i ran dom chooose i right:))

int minMoves2(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int t = nums[int(n / 2)];
    int res = 0;

    for (auto i : nums)
        res += abs(i - t);
    return res;
}