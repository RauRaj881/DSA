class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);  // For lowercase letters a-z

        for (char ch : magazine)
            freq[ch - 'a']++;

        for (char ch : ransomNote) {
            if (freq[ch - 'a'] == 0)
                return false;
            freq[ch - 'a']--;
        }

        return true;
    }
};
