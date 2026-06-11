class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <char> uni;
        int left=0; int right =0;
        int maxLen=0;

        while(right<s.size())
        {
            if(uni.find(s[right])==uni.end())
            {
                uni.insert(s[right]);
                maxLen=max(maxLen,right-left+1);
                right++;

            }
            else
            {
                uni.erase(s[left]);
                left++;
            }

        }
        return maxLen;
    }
};
