/*
�����ַ���
��Map��ȡ����ǰλ��������������Ӧ������
����ǰλ��������ǰһλ���бȽ�
�����ǰλС��ǰһλ
˵��û��������� ֱ�Ӽ�����λ
�����ǰλ����ǰһλ
˵�����������
��Ҫ���ϵ�ǰλ��ȥǰһλ������
����Ϊǰһλ����һ��ѭ�������һ��
���Ի�Ҫ��һ��
��󽫵�ǰλ����ǰһλ
��ǰλ����һ��ѭ����ǰһλ
����
����: "MCMXCIV"
���: 1994
����: M = 1000, CM = 900, XC = 90, IV = 4.
ǰһλ��ʼΪ0 �����ʼΪ0
��һ��M��ǰһλ��
result = result + M - 0 * 2 = 0 + 1000 - 0 * 2 = 1000
�ڶ���C��ǰһλС
result = result + C = 1000 + 100 = 1100
������M��C�� �������������
result = result + (M - C) - C (C����һ�ζ����һ��) = 1100 + 900 - 100 = 1900
�Դ�����
*/


class Solution {
    private static HashMap<String,Integer> roman = new HashMap<>();

    static
    {
        roman.put("I",1);
        roman.put("V",5);
        roman.put("X",10);
        roman.put("L",50);
        roman.put("C",100);
        roman.put("D",500);
        roman.put("M",1000);
    }
    
    public int romanToInt(String s) {
        // ��¼�ַ�������
        int len = s.length();
        // ��� Ĭ��Ϊ0
        int result = 0;
        // ��¼֮ǰһλ�������ֶ�Ӧ�Ľ�� ��ʼ��Ϊ0
        int preInt = 0;

        // �����ַ���
        for(int i = 0;i < len;i++)
        {
            String pos = s.substring(i,i+1);
            int posInt = roman.get(pos);

            // ���ǰһ�����ֱȵ�ǰλС
            if(posInt > preInt)
            {
                // ����ϵ�ǰλ����ȥ֮ǰ��λ��
                result += posInt;
                // ��Ҫ��ȥ֮ǰ��λ��ӵ� ����֮ǰ��λ *2
                result -= preInt * 2;
            }
            else
            {
                // ����ֱ�Ӽ��ϵ�ǰ��λ��
                result += posInt;
            }
            // ѭ������ʱ ��ǰ���ֻ����´�ѭ����ǰһλ
            preInt = posInt;
        }
        return result;
    }
}





/*
һ����switch�������ַ�����Ȼ�������������洢ÿ���ַ����Ĵ���ֵ
Ȼ��ͨ���ж������������ӣ�
*/
static const auto io_sync_off=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();
class Solution {
public:

    int romanToInt(string s) {        
        int sum = 0;
        int n[s.size()+1];
        n[s.size()]=0;
        for(int i = 0; i < s.length(); i++){           
            switch(s[i]){
                case 'I':  n[i]=1; break;
                case 'V':  n[i]=5; break;
                case 'X':  n[i]=10; break;
                case 'L':  n[i]=50; break;
                case 'C':  n[i]=100; break;
                case 'D':  n[i]=500; break;
                case 'M':  n[i]=1000; break;
                default :break;             
            }
        }
        //������int n[100]; n['I']=1;....��ʾ
        
        for(int i = 0; i < s.length(); i++){
            if(n[i] < n[i+1]) {
                sum = sum + n[i+1] - n[i];
                i++;
            }else
                sum += n[i];
        }
       
        return sum;
    } 
};