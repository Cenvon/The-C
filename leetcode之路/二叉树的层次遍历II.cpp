˼·��������Ĳ��������ÿ�����һά������Ȼ��һά���������ά��������ά����Ԫ�ط�ת�����

�ݹ�ⷨ��
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> nums;
        postorder(root,0,nums);//����ݹ�
        reverse(nums.begin(),nums.end());//��reverse��ת����Ԫ��Ȼ�������
        return nums;
        
    }
    void postorder(TreeNode* root,int level,vector<vector<int>>& ans)//�ݹ麯��
    {
        if(!root)  return;
        if(level>=ans.size())  ans.push_back({});
        postorder(root->left,level+1,ans);
        postorder(root->right,level+1,ans);
        ans[level].push_back(root->val);
    }
};


�����ⷨ��
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;

    vector<TreeNode*> stk, emptyStk;
    stk.push_back(root);
    while (!stk.empty()) {
        vector<int> layer;
        vector<TreeNode*> nodeList(stk.begin(), stk.begin()+stk.size());
        stk = emptyStk;
        for (TreeNode* node : nodeList) {
            layer.push_back(node->val);
            if (node->left) stk.push_back(node->left);
            if (node->right) stk.push_back(node->right);
        }
        ans.push_back(layer);
    }
    reverse(ans.begin(), ans.begin()+ans.size());
    return ans;
}
};