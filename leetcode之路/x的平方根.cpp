static const void* ___ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	int mySqrt(int x) {
		if (x == 1 || x == 0) return x;
		unsigned v = x / 2;
		while (true)
		{
			unsigned v2 = x / v;
			if (v2 >= v) return v;
			v = (v + v2) >> 1;//二进制右移一位（删除最后一位）
		}
	}
};