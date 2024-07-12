class Solution {
    int getPoints(string& s, string str, int points) {
        int totalPoints = 0, n = s.length();
        int readIndex = 0, writeIndex = 0;
        for (readIndex; readIndex < n; readIndex++) {
            s[writeIndex++] = s[readIndex];
            if (writeIndex > 1 && s[writeIndex - 1] == str[1] &&
                s[writeIndex - 2] == str[0]) {
                totalPoints += points;
                writeIndex -= 2;
            }
        }
        s = s.substr(0, writeIndex);
        return totalPoints;
    }

public:
    int maximumGain(string s, int x, int y) {
        string s1 = "ab", s2 = "ba";
        if (x < y)
            swap(s1, s2), swap(x, y);
        return getPoints(s, s1, x) + getPoints(s, s2, y);
    }
};