执行用时 : 12 ms, 在Search Insert Position的C++提交中击败了16.06% 的用户
内存消耗 : 8.7 MB, 在Search Insert Position的C++提交中击败了0.27% 的用户

static int x = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

//复杂版
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int next=0;
        
//         if(nums.size()==0)//考虑数组为0的情况
//             return -1;
        
        for(int i=0;i<nums.size();i++){//遍历nums，寻找target
            
            if(nums[i]==target)//如果从数组中找到值就返回位置i
                return i;
            
            if(nums[0]>target)//如果小于第一个数，直接返回next
                return next;
            
            if(nums[nums.size()-1]<target)//如果大于最后一个元素就输出最后一个元素的后一个位置
                return nums.size();
            
            if((i!=nums.size()-1)&&nums[i+1]>=target&&nums[i]<=target)//在不是最后一个元素的情况下，记录不小于target的数的位置
                next = i+1;
        }
        return next;//如果数组中不存在target就输出next
    }
};


//简化版
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
            if(nums[i]>=target)
                return i;
        return nums.size();
    }
};