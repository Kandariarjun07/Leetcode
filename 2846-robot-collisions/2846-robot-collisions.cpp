class Solution {
    typedef tuple<int, int, char, int> tup;
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<tup> robots(n);

        for (int i = 0; i < n; i++) {
            robots[i] = {positions[i], healths[i], directions[i], i};
        }

        sort(robots.begin(), robots.end());

        stack<tup> st;
        for (int i = 0; i < n; i++) {
            int currPos = get<0>(robots[i]);
            int currHealth = get<1>(robots[i]);
            char currDirec = get<2>(robots[i]);
            int currIndex = get<3>(robots[i]);

            if (st.empty() || currDirec == 'R' || get<2>(st.top()) == 'L') {
                st.push(robots[i]);
            } else {
                while (!st.empty() && currDirec == 'L' &&
                       get<2>(st.top()) == 'R') {
                    auto p = st.top();
                    st.pop();
                    if (get<1>(p) == currHealth) {
                        currHealth = 0;
                        break;
                    } else if (get<1>(p) > currHealth) {
                        get<1>(p) -= 1;
                        st.push(p);
                        currHealth = 0;
                        break;
                    } else {
                        currHealth--;
                    }
                }
                if (currHealth > 0) {
                    st.push({currPos, currHealth, currDirec, currIndex});
                }
            }
        }

        vector<tup> survived;
        while (!st.empty()) {
            survived.push_back(st.top());
            st.pop();
        }

        sort(survived.begin(), survived.end(),
             [](tup a, tup b) { return get<3>(a) < get<3>(b); });

        vector<int> ans;
        for (auto& robot : survived) {
            ans.push_back(get<1>(robot));
        }

        return ans;
    }
};