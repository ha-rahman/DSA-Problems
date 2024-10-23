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
    TreeNode* replaceValueInTree(TreeNode* root) {
        int prevLevelSum = root->val;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int levelSize = q.size(), currSum = 0;
            for(int i=0; i<levelSize; i++){
                TreeNode *node = q.front(); q.pop();
                node->val = prevLevelSum - node->val;
                int siblingSum = (node->left ? node->left->val : 0) + (node->right ? node->right->val : 0);

                if(node->left){
                    currSum += node->left->val;
                    node->left->val = siblingSum;
                    q.push(node->left);
                }
                if(node->right){
                    currSum += node->right->val;
                    node->right->val = siblingSum;
                    q.push(node->right);
                }
            }
            prevLevelSum = currSum;
        }
        return root;
    }
};