ִ����ʱ : 12 ms, ��Search Insert Position��C++�ύ�л�����16.06% ���û�
�ڴ����� : 8.7 MB, ��Search Insert Position��C++�ύ�л�����0.27% ���û�

static int x = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

//���Ӱ�
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int next=0;
        
//         if(nums.size()==0)//��������Ϊ0�����
//             return -1;
        
        for(int i=0;i<nums.size();i++){//����nums��Ѱ��target
            
            if(nums[i]==target)//������������ҵ�ֵ�ͷ���λ��i
                return i;
            
            if(nums[0]>target)//���С�ڵ�һ������ֱ�ӷ���next
                return next;
            
            if(nums[nums.size()-1]<target)//����������һ��Ԫ�ؾ�������һ��Ԫ�صĺ�һ��λ��
                return nums.size();
            
            if((i!=nums.size()-1)&&nums[i+1]>=target&&nums[i]<=target)//�ڲ������һ��Ԫ�ص�����£���¼��С��target������λ��
                next = i+1;
        }
        return next;//��������в�����target�����next
    }
};


//�򻯰�
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
            if(nums[i]>=target)
                return i;
        return nums.size();
    }
};