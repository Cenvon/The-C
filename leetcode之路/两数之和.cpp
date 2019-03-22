class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;//������������
        unordered_map<int, int> hash;//����ͼ���������Ϊpython�е��ֵ����ͣ�
        for (int i = nums.size() - 1;i >= 0; hash[nums[i]] = i, i--)
        {
	    /*
	    hash[nums[i]]=i   hash�������ֵ��Ϊ���������������±���Ϊ��ֵ����
	    ͨ���Լ��Ĳ�ѯ���ҵ���Ӧ�ļ����������������ġ�ֵ�����浽vector�С�
		���磺
			������nums[n],���䰴�˹�������map�������£�

			��           ֵ
			nums[0]   :  0
			nums[1]   :  1
			nums[2]   :  2
			...
			nums[n]   :  n
	    */

            if (hash.find(target - nums[i]) == hash.end())
	    /*
	    find��������������hash��û�з���Ŀ���ʱ��
	    ��������end������ʱδ����Ŀ�������ô���������Ԫ�ء�
            */
		continue;
            v.push_back(i);//�����ֵļ���������v
            v.push_back(hash[target - nums[i]]);//����һ������������v
            return v;
        }
        return v;
    }
};