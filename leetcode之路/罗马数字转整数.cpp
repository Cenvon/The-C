/*
遍历字符串
从Map中取出当前位的罗马数字所对应的数字
将当前位的数字与前一位进行比较
如果当前位小于前一位
说明没有特殊情况 直接加上这位
如果当前位大于前一位
说明是特殊情况
需要加上当前位减去前一位的数字
又因为前一位在上一次循环多加了一次
所以还要减一次
最后将当前位赋给前一位
当前位是下一次循环的前一位
例子
输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
前一位初始为0 结果初始为0
第一次M比前一位大
result = result + M - 0 * 2 = 0 + 1000 - 0 * 2 = 1000
第二次C比前一位小
result = result + C = 1000 + 100 = 1100
第三次M比C大 所以是特殊情况
result = result + (M - C) - C (C在上一次多加了一次) = 1100 + 900 - 100 = 1900
以此类推
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
        // 记录字符串长度
        int len = s.length();
        // 结果 默认为0
        int result = 0;
        // 记录之前一位罗马数字对应的结果 初始化为0
        int preInt = 0;

        // 遍历字符串
        for(int i = 0;i < len;i++)
        {
            String pos = s.substring(i,i+1);
            int posInt = roman.get(pos);

            // 如果前一个数字比当前位小
            if(posInt > preInt)
            {
                // 则加上当前位数减去之前的位数
                result += posInt;
                // 还要减去之前那位多加的 所以之前那位 *2
                result -= preInt * 2;
            }
            else
            {
                // 否则直接加上当前这位数
                result += posInt;
            }
            // 循环结束时 当前数字会变成下次循环的前一位
            preInt = posInt;
        }
        return result;
    }
}





/*
一次用switch来遍历字符串，然后用新数组来存储每个字符串的代表值
然后通过判断来相减或者相加；
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
        //可以用int n[100]; n['I']=1;....表示
        
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