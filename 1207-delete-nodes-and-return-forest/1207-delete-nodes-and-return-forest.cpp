class Solution {
public:
    TreeNode* Helper(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& ans) {
        if (root == NULL)
            return NULL;
        
        root->left = Helper(root->left, st, ans);
        root->right = Helper(root->right, st, ans);
        
        if (st.find(root->val) != st.end()) {
            if (root->left != NULL)
                ans.push_back(root->left);
            if (root->right != NULL)
                ans.push_back(root->right);
            return NULL;
        }
        
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> st(to_delete.begin(), to_delete.end()); 
        root = Helper(root, st, ans);
        
        if (root != NULL && st.find(root->val) == st.end())
            ans.push_back(root);
        
        return ans;
    }
};