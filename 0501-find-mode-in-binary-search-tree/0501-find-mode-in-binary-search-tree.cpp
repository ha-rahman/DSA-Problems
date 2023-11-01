/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front(); q.pop();
            mp[node->val]++;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        int mxFreq = 0;
        for(auto [key, val] : mp) mxFreq = max(mxFreq, val);
        vector<int> ans;
        for(auto [key, val] : mp){
            if(mxFreq == val) ans.push_back(key);
        }
        return ans;
    }
};