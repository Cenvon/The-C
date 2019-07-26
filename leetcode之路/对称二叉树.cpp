/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



//思路：构造一个新函数在原函数里面调用，然后再新函数里面调用递归
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return ismirror(root,root);
    }
    
    bool ismirror(TreeNode* p,TreeNode* q){
        if(!p&&!q)//都为NULL
            return true;
        if(!p||!q)//有一个为NULL
            return false;
        if(p->val==q->val)
            return ismirror(p->left,q->right)&&ismirror(p->right,q->left);
        return false;
    }
};