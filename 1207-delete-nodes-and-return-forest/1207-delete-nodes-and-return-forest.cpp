class Solution {
public:
    //Appraoch:- SO FIRST THINGS WHEN WE HAVE TO DELETE ANY GIVEN NODE WE NEED CONFIRMED THAT IF THERE IS ANY CHILD SUBTREE IS FORMED FROM THAT NODE SO WE NEED TO MAKE SURE THAT WE HAVE A ACCESS OF THAT FOREST TREE. 
    // SO FOR THIS WE WILL DO LIKE FIRST WE WILL GO IN THE DEPTH OF THE TREE AND AFTER REACHING THE LAST NODE OF THAT TREE WE COME UPWORD OR BACKTRACK.AND NOW CHECK WETHER WE HAVE TO DELETE THAT NODE OR NOT AND NOW IF WE HAVE TO DELETE THAT NODE THEN WE WILL SIMPLY ADD THE ROOT OF SUBTREE INTO THE RESULT AND THEN DELET THAT NODE . SO BY DOING THIS WE KEEP ENSURE THAT WE HAVE ACCESS OF FOREST TREE.
    TreeNode* Helper(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& ans) {
        //TO REACH THE LAST NODE FIRST WE WILL DO DFS.
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