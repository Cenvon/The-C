/*
���������δ���ԭ��ȡģ10������
Ȼ���ٴ������д�ͷ��β��������õ���ת���ֵ�Ч����
���ͨ���Ƚ�int�����ݷ�Χ�ó��Ƿ��ж�Ӧ��ֵ��
*/

class Solution {
public:
    int reverse(int x) {
        int tmp = x,flag = 0;
        long result = 0;
        vector<int> a;
        while(tmp){
            a.push_back(tmp % 10);//��ĩβ��ʼ���ÿ������
            tmp = tmp / 10;
        }
        for(int i = 0;i <a.size(); i++){
            result = result * 10 + a[i];
        }
        if (result > pow(2,31) - 1 || result < -1 * pow(2,31))
            return 0;
        return result;
    
    }
};

/*
����˼·��������һ����
�����˴�����һ���������Ŀ��������������ʱ��
�˴�ʡ�ԵĲ���Ҫ�Ĳ��裬ʹ����Ŀ���������Ĵ���
*/

static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
	    while (x != 0) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
	    return (ans > INT_MAX || ans < INT_MIN) ? 0 : ans;
	    //return (ans<=INT_MAX&&ans>=INT_MIN)?ans:0;   �˴����������ԭ���� ����󲿷����ݶ��Ƿ��Ϸ�Χ�ģ��������ȿ����Ƿ񳬳�
}
};