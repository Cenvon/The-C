class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int c = 0, a_length = a.size() - 1, b_length = b.size() - 1;

        while(a_length >= 0 || blength >= 0 || c == 1)
        {
            c += (a_length >= 0 ? a[i --] - '0' : 0);//��string��ÿһλ��asc���������Ȼ��õ���Ӧ��int������ʵ����Ϊ�˵õ�int����
            c += (b_length >= 0 ? b[j --] - '0' : 0);
            s = char(c % 2 + '0') + s;     //ǰһ��䵱��λ�����Ȼ����ԭ����s�����ӣ�
                                           //�൱����sǰ�����˸��� 
            c /= 2;    //�䵱��λ
        }
        return s;
    }
};