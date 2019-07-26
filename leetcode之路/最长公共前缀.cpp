static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        string prefix=strs[0];
        for(auto i=1;i<strs.size();i++)
        {
            int j=0,len=min(prefix.size(),strs[i].size());
            while(j<len && prefix[j]==strs[i][j])j++;
            prefix.erase(prefix.begin()+j,prefix.end());
            if(prefix=="")
                break;
        }
        return prefix;
    }
};