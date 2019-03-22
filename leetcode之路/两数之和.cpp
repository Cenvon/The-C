class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;//创建留存向量
        unordered_map<int, int> hash;//创建图（可以理解为python中的字典类型）
        for (int i = nums.size() - 1;i >= 0; hash[nums[i]] = i, i--)
        {
	    /*
	    hash[nums[i]]=i   hash表把数组值作为“键”，把数组下标作为“值”。
	    通过对键的查询来找到对应的键，最后输出两个键的“值”保存到vector中。
		例如：
			有数组nums[n],则其按此规则做的map就是如下：

			键           值
			nums[0]   :  0
			nums[1]   :  1
			nums[2]   :  2
			...
			nums[n]   :  n
	    */

            if (hash.find(target - nums[i]) == hash.end())
	    /*
	    find迭代器遍历整个hash表都没有发现目标键时，
	    即遍历到end迭代器时未发现目标键，那么便继续填入元素。
            */
		continue;
            v.push_back(i);//将发现的键加入向量v
            v.push_back(hash[target - nums[i]]);//将另一个键加入向量v
            return v;
        }
        return v;
    }
};