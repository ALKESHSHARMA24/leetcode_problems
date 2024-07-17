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
    //APPRAOCH:- FOR THIS QUESTION WE CAN SEE THAT WE HAVE TO JUST RETURN THE LAST ELMENENT OF THE CURRENT LEVEL.AND TO FIND THE ALL NODES AT THE CURRENT LEVEL BY LEVEL WE CAN PERFORM A BFS TARVERSEL WHICH ALSO CALLED A LEVEL BY LEVEL TRAVERSAL.

    vector<int> rightSideView(TreeNode* root) {
        if(root ==NULL){
            return {};
        }

        vector<int> result;
        queue<TreeNode*> qu;
        qu.push(root);
        TreeNode* node;

        while(!qu.empty()){
            int n=qu.size();
            while(n--){ //WE ARE USING ANOTHER INNER WHILE LOOP TO CHECK THAT WHENEVER WE ARE EXPLORING THE LAST NODE OF THE CURRENT LEVEL SO WE NEED PUSH IT INTO THE RESULT AS IT WILL BE RIGHT MOST NODE FOR THE CURRENT LEVEL.
                node=qu.front();
                qu.pop();
                if(node->left!=NULL) qu.push(node->left);
                if(node->right!=NULL) qu.push(node->right);
            }
            //WHILE LOOP BREAKS SO OUR LAST ASSIGNED NODE WILL BE RIGHT MOST NODE OF THE CURRENT LEVEL.
            result.push_back(node->val); 
        }

        return result;
        
    }
};