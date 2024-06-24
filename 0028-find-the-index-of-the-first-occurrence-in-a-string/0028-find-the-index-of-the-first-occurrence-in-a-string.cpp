class Solution {
#define ll long long
#define MOD 1000000007
    ll makeHash(string s, ll RADIX, int m) {
        ll hash = 0, MAX_WEIGHT = 1;
        for (int i = m - 1; i >= 0; --i) {
            hash = (hash + (s[i] - 'a' + 1) * MAX_WEIGHT) % MOD;
            MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD;
        }
        return hash % MOD;
    }

public:
    int strStr(string haystack, string needle) {
        int m = needle.length(), n = haystack.length();
        if (m > n)
            return -1;
        if (m == 0)
            return 0;

        ll RADIX = 26;
        ll needleHash = makeHash(needle, RADIX, m);
        ll haystackHash = makeHash(haystack, RADIX, m);

        ll MAX_WEIGHT = 1;
        for (int i = 1; i < m; ++i) {
            MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD;
        }
        for (int i = 0; i <= n - m; i++) {
            if (needleHash == haystackHash) {
                if (haystack.substr(i, m) == needle) {
                    return i;
                }
            } 
            if (i < n - m) {
                haystackHash = (haystackHash - (haystack[i] - 'a' + 1) * MAX_WEIGHT % MOD + MOD) % MOD;
                haystackHash = (haystackHash * RADIX % MOD + (haystack[i + m] - 'a' + 1)) % MOD;
            }
        }
        return -1;
    }
};