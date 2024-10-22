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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>arr;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int size=q.size();
            long long sum=0;
           while(size--)
           {
              TreeNode* node=q.front();
              q.pop();
              sum+=node->val;

              if(node->left)
              q.push(node->left);

               if(node->right)
              q.push(node->right);

           }
           arr.push_back(sum);
        }

        sort(arr.begin(),arr.end());
        
        int n=arr.size();

        if(k>n)
        return -1;

        return arr[n-k];
    }
};