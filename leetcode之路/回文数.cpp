/*
��������תһ�����������������к�õ���ֵ���������ֵ��ô���ǻ�������
����ǻ���������ô�������������Ϊ���洢��ʱ��������ֵ��
*/


static int x = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }   
        int reverseNumber = 0;
        while (x > reverseNumber) {
            reverseNumber = reverseNumber * 10 + x % 10;
            x /= 10;
        }
        return x == reverseNumber || x == reverseNumber / 10;
    }
};