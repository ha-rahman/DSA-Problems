class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        return f(0, amount, coins, dp);
    }
    int f(int i, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(amount == 0) return 1;
        if(i == coins.size()) return 0;
        if(dp[i][amount] != -1) return dp[i][amount];
        if(coins[i] > amount) return dp[i][amount] = f(i+1, amount, coins, dp);
        int take = f(i, amount-coins[i], coins, dp);
        int notTake = f(i+1, amount, coins, dp);
        dp[i][amount] = take+notTake;
        return dp[i][amount];
    }
};