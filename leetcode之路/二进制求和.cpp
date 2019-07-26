class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int c = 0, a_length = a.size() - 1, b_length = b.size() - 1;

        while(a_length >= 0 || blength >= 0 || c == 1)
        {
            c += (a_length >= 0 ? a[i --] - '0' : 0);//把string中每一位的asc码减出来，然后得到对应的int数（其实就是为了得到int数）
            c += (b_length >= 0 ? b[j --] - '0' : 0);
            s = char(c % 2 + '0') + s;     //前一项充当该位结果，然后与原来的s相连接，
                                           //相当于在s前插入了该项 
            c /= 2;    //充当进位
        }
        return s;
    }
};