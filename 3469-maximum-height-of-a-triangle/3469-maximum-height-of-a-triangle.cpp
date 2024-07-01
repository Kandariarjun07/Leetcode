class Solution {
    // 0 for red .....
    // 1 for blue .....
    int findHeight(int currHeight, int currColor, int red, int blue) {
        if (currColor == 0 && currHeight + 1 > red ||
            currColor == 1 && currHeight + 1 > blue)
            return currHeight;
        return currColor == 0 ? findHeight(currHeight + 1, !currColor,
                                           red - currHeight - 1, blue)
                              : findHeight(currHeight + 1, !currColor, red,
                                           blue - currHeight - 1);
    }

public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(findHeight(0, 0, red, blue), findHeight(0, 1, red, blue));
    }
};