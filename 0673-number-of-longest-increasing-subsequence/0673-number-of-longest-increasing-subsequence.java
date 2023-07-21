class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length, mxLen = 0;
        int[] length = new int[n];
        int[] cnt = new int[n];
        Arrays.fill(length, 1);
        Arrays.fill(cnt, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    if(length[j] + 1 > length[i]){
                        length[i] = length[j] + 1;
                        cnt[i] = 0;
                    }
                    if(length[j] + 1 == length[i]){
                        cnt[i] += cnt[j];
                    }
                }
            }
            mxLen = Math.max(mxLen, length[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(length[i] == mxLen){
                ans += cnt[i];
            }
        }
        return ans;
    }
}