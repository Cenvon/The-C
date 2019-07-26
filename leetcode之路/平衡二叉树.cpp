class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)                                                //��Ϊ��
            return true;
        if(abs(countFloor(root->left)-countFloor(root->right))>1)//����ֵ>1
            return false;
        else
            return isBalanced(root->left) && isBalanced(root->right);
    }
    int countFloor(TreeNode* root){                              //���������
        if(!root)                                                //����Ҷ�ӽڵ�ʱ����0
            return 0;
        return 1+max(countFloor(root->left),countFloor(root->right));
    }
};