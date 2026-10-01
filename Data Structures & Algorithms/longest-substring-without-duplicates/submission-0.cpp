class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int len = 0, maxLen = 0;
        int l = 0, r = 0;
        while(r < s.size()) {
            while(mp.find(s[r]) != mp.end()) {
                mp[s[l]]--;
                if(mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }
            mp[s[r]]++;
            
            len = r-l+1;
            maxLen = max(len, maxLen);
            r++;
        }
        return maxLen;
    }
};
