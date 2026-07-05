class Solution {
public:
    bool canMakeSubsequence(string s, string t){
        int n1 = s.size();
        int n2 = t.size();
        
        if (n1 > n2) return false;
        vector<int> left(n1, 1e9); 
        int j = 0;
        for (int i = 0; i < n1; i++) {
            while (j < n2 && t[j] != s[i]) j++;
            if (j < n2) {
                left[i] = j;
                j++; 
            } else {
                break; 
            }
        }
        if (left[n1 - 1] != 1e9) return true;
        vector<int> right(n1, -1e9);
        j = n2 - 1;
        for (int i = n1 - 1; i >= 0; i--) {
            while (j >= 0 && t[j] != s[i]) j--;
            if (j >= 0) {
                right[i] = j;
                j--;
            } else {
                break;
            }
        }
        for (int k = 0; k < n1; k++) {
            int l_idx = (k == 0) ? -1 : left[k - 1];
            int r_idx = (k == n1 - 1) ? n2 : right[k + 1];
            //if (l_idx != 1e9 && r_idx != -1e9) {
                if (r_idx - l_idx >= 2) {
                    return true;
                }
            //}
        }

        return false;
    }
};