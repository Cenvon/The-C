class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)                                                //树为空
            return true;
        if(abs(countFloor(root->left)-countFloor(root->right))>1)//绝对值>1
            return false;
        else
            return isBalanced(root->left) && isBalanced(root->right);
    }
    int countFloor(TreeNode* root){                              //计算树层高
        if(!root)                                                //到达叶子节点时返回0
            return 0;
        return 1+max(countFloor(root->left),countFloor(root->right));
    }
};