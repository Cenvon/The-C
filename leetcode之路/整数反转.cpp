/*
用数组依次存入原数取模10的余数
然后再从数组中从头到尾依次输出得到翻转数字的效果。
最后通过比较int的数据范围得出是否有对应的值。
*/

class Solution {
public:
    int reverse(int x) {
        int tmp = x,flag = 0;
        long result = 0;
        vector<int> a;
        while(tmp){
            a.push_back(tmp % 10);//从末尾开始存放每个数字
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
基本思路与上面是一样的
不过此处加了一个输入流的控制来减少输入的时间
此处省略的不必要的步骤，使用三目运算符精简的代码
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
	    //return (ans<=INT_MAX&&ans>=INT_MIN)?ans:0;   此处不用这个的原因是 假设大部分数据都是符合范围的，所以优先考虑是否超出
}
};