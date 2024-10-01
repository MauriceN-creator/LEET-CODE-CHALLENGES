class Solution {
    void push(vector<string>& ans, stack<int>& st, int& val) {
        st.push(val);
        ans.push_back("Push");
    }

public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> st;
        vector<string> ans;

        // Push elements from 1 to n onto the stack
        for (int i = 1; i <= n; i++) {
            push(ans, st, i);
        }

        while (st.top() != target.back()) {
            // Pop elements from the stack and remove corresponding "Push" actions
            st.pop();
            ans.pop_back();
        }

        if (st.empty()) {
            // If the stack is empty, it's impossible to reach the target
            return {"-1"};
        }

        int idx = target.size() - 1;
        int ansIdx = ans.size() - 1;

        while (!st.empty() && idx >= 0) {
            if (st.top() == target[idx]) {
                idx--;
            } else {
                ans.insert(ans.begin() + ansIdx + 1, "Pop");
            }
            st.pop();
            ansIdx--;
        }

        // check wheather ans vector contains number which is not present in the target list

        //cases like : 2,5,6 n=7
        while (ansIdx >= 0) {
            ans.insert(ans.begin() + ansIdx + 1, "Pop");
            ansIdx--;
        }

        return ans;
    }
};