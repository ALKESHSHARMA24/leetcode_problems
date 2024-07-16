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

    /*
    //APPROACH:- 1.FIND LCA
                 2.FIND THE DIRECTION FROM ROOT TO SRC 
                 3. FIND THE DIRECTION FORM ROOT TO DEST
                 4.AS WE KNOW TO FIND DIR FRM SRC TO DEST FIRST WE HAVE TO THOUGH THE LCM WHICH CAN BE ALSO CALLED A LOWEST COMMON PARENT FOR BOTH.
SO FOR THAT WE HAVE TO ALWAYS MOVE 'U' TO PARENT. SO FOR  TILL THAT DISTANCE WE WILL ADD THE 'U' IN RESULT.
THEN WE HAVE TO ADD THE DIRECTION FORM THE SRC TO DESTINATION INTO RESULT.
    */
TreeNode* findLca(TreeNode*root ,int startval,int destval){
    if(root==nullptr){
        return nullptr;
    }
    if(root->val==startval || root->val==destval){
        return root;
    }
    
    TreeNode* leftLca=findLca(root->left,startval,destval);
    TreeNode* rightLca=findLca(root->right,startval,destval);
    if(leftLca && rightLca){
        return root;
    }
    return (leftLca != nullptr) ? leftLca:rightLca;
}
    bool findDirection(TreeNode* root,int target,string& dir){
        if(root==nullptr){
            return false;
        }

        if(root->val==target){
            return true;
        }
        //traverse on the left subtree
        dir.push_back('L');
        if(findDirection(root->left,target,dir)==true){
            return true;
        }
        dir.pop_back();//IF DON'T FIND TARGET IN THE LEFT SUBTREE THEN REOMVE THE L.

        dir.push_back('R');

        if(findDirection(root->right,target,dir)==true){
            return true;
        }
        dir.pop_back();//IF NOT FOUND TARGET IN THE RIGHT PART THEN REMOVE THE ADD 'R' FROM THE STRING.
        return false;

    }
    string getDirections(TreeNode* root, int startval, int destval) {
        TreeNode* LCA=findLca(root,startval,destval);

        string roottoSrc="";
        string roottoDest="";
        findDirection(LCA,startval ,roottoSrc);
        findDirection(LCA,destval,roottoDest);

        string result="";

        for(int i=0;i<roottoSrc.length();i++){
            result+='U';
        }
        result+=roottoDest;
        return result;
    }
};