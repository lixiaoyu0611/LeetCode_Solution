class Solution {
    public int rob(int[] nums) {
    int[][] DP = new int[nums.length + 1][2];
    for (int i = 1; i <= nums.length; i++) {
        DP[i][0] = Math.max(DP[i - 1][0], DP[i - 1][1]);
        DP[i][1] = nums[i - 1] + DP[i - 1][0];
    }
    return Math.max(DP[nums.length][0], DP[nums.length][1]);
    }
}