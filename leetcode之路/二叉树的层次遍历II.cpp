思路：先正序的层序遍历的每层存入一维向量，然后将一维向量存入二维向量，二维向量元素反转后输出

递归解法：
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> nums;
        postorder(root,0,nums);//进入递归
        reverse(nums.begin(),nums.end());//用reverse反转数组元素然后再输出
        return nums;
        
    }
    void postorder(TreeNode* root,int level,vector<vector<int>>& ans)//递归函数
    {
        if(!root)  return;
        if(level>=ans.size())  ans.push_back({});
        postorder(root->left,level+1,ans);
        postorder(root->right,level+1,ans);
        ans[level].push_back(root->val);
    }
};


迭代解法：
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