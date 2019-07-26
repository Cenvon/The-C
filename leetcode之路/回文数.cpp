/*
与整数反转一样如果倒序的数字排列后得到的值等于正序的值那么就是回文数；
如果是回文数，那么它不会溢出；因为它存储的时候就是这个值。
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