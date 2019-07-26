/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



//˼·������һ���º�����ԭ����������ã�Ȼ�����º���������õݹ�
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return ismirror(root,root);
    }
    
    bool ismirror(TreeNode* p,TreeNode* q){
        if(!p&&!q)//��ΪNULL
            return true;
        if(!p||!q)//��һ��ΪNULL
            return false;
        if(p->val==q->val)
            return ismirror(p->left,q->right)&&ismirror(p->right,q->left);
        return false;
    }
};