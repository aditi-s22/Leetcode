class Solution {
public:
    char processStr(string s, long long k) {

        int n = s.size();

        vector<long long> len(n);

        long long cur = 0;

        for(int i = 0; i < n; i++) {

            char ch = s[i];

            if(ch >= 'a' && ch <= 'z') {

                cur++;
            }
            else if(ch == '*') {

                if(cur > 0)
                    cur--;
            }
            else if(ch == '#') {

                cur = min(cur * 2, (long long)4e18);
            }
            else if(ch == '%') {

                // length unchanged
            }

            len[i] = cur;
        }

        if(k >= cur)
            return '.';

        for(int i = n - 1; i >= 0; i--) {

            char ch = s[i];

            long long prevLen =
                (i == 0 ? 0 : len[i - 1]);

            if(ch >= 'a' && ch <= 'z') {

                if(k == prevLen)
                    return ch;
            }
            else if(ch == '*') {

                // backward: deleted char restored
            }
            else if(ch == '#') {

                if(prevLen > 0)
                    k %= prevLen;
            }
            else if(ch == '%') {

                if(prevLen > 0)
                    k = prevLen - 1 - k;
            }
        }

        return '.';
    }
};