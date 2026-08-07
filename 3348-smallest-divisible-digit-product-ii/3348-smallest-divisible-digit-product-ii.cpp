class Solution {
public:
    array<int,4> contrib[10]; // digit -> (exp2, exp3, exp5, exp7)
    unordered_map<long long, int> memo;
    array<int,4> target;

    long long encode(array<int,4> s) {
        return ((long long)s[0]*100 + s[1])*100*100 + (long long)s[2]*100 + s[3];
    }

    array<int,4> subState(array<int,4> state, int dg) {
        array<int,4> r;
        for (int k = 0; k < 4; k++) r[k] = max(state[k] - contrib[dg][k], 0);
        return r;
    }

    int minDigits(array<int,4> state) {
        if (state[0]==0 && state[1]==0 && state[2]==0 && state[3]==0) return 0;
        long long key = encode(state);
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;
        int best = INT_MAX;
        for (int dg = 2; dg <= 9; dg++) {
            array<int,4> ns = subState(state, dg);
            if (ns != state) {
                int val = 1 + minDigits(ns);
                best = min(best, val);
            }
        }
        memo[key] = best;
        return best;
    }

    array<int,4> addCapped(array<int,4> total, int dg) {
        array<int,4> r;
        for (int k = 0; k < 4; k++) r[k] = min(total[k] + contrib[dg][k], target[k]);
        return r;
    }

    string buildSuffix(array<int,4> rem, int length) {
        string res;
        array<int,4> cur = rem;
        for (int pos = 0; pos < length; pos++) {
            int remainingLen = length - pos - 1;
            for (int dg = 1; dg <= 9; dg++) {
                array<int,4> ns = subState(cur, dg);
                if (minDigits(ns) <= remainingLen) {
                    res += char('0' + dg);
                    cur = ns;
                    break;
                }
            }
        }
        return res;
    }

    string smallestNumber(string num, long long t) {
        // digit contributions
        contrib[1] = {0,0,0,0};
        contrib[2] = {1,0,0,0};
        contrib[3] = {0,1,0,0};
        contrib[4] = {2,0,0,0};
        contrib[5] = {0,0,1,0};
        contrib[6] = {1,1,0,0};
        contrib[7] = {0,0,0,1};
        contrib[8] = {3,0,0,0};
        contrib[9] = {0,2,0,0};

        // ---- Step 1: factor t into 2^a * 3^b * 5^c * 7^d ----
        int a = 0, b = 0, c = 0, d = 0;
        long long rem = t;
        int primes[4] = {2,3,5,7};
        int* exps[4] = {&a,&b,&c,&d};
        for (int i = 0; i < 4; i++) {
            while (rem % primes[i] == 0) { rem /= primes[i]; (*exps[i])++; }
        }
        if (rem != 1) return "-1";

        target = {a, b, c, d};
        int Lmin = minDigits(target);

        int n = num.size();
        vector<int> digits(n);
        for (int i = 0; i < n; i++) digits[i] = num[i] - '0';

        // ---- Case 0: num itself already works ----
        bool zeroFree = true;
        for (int dg : digits) if (dg == 0) { zeroFree = false; break; }
        if (zeroFree) {
            array<int,4> state = {0,0,0,0};
            for (int dg : digits) state = addCapped(state, dg);
            if (state == target) return num;
        }

        // ---- Case A: same length n ----
        int z = n;
        for (int i = 0; i < n; i++) if (digits[i] == 0) { z = i; break; }
        int startI = min(n - 1, z);

        vector<array<int,4>> prefixExp(n + 1, array<int,4>{0,0,0,0});
        for (int i = 0; i < n; i++) {
            if (i < z) prefixExp[i+1] = addCapped(prefixExp[i], digits[i]);
            else prefixExp[i+1] = prefixExp[i];
        }

        string answer = "";
        for (int i = startI; i >= 0; i--) {
            array<int,4> base = prefixExp[i];
            array<int,4> remAfterPrefix;
            for (int k = 0; k < 4; k++) remAfterPrefix[k] = max(target[k] - base[k], 0);
            int suffixLen = n - 1 - i;
            for (int dg = digits[i] + 1; dg <= 9; dg++) {
                array<int,4> ns = subState(remAfterPrefix, dg);
                if (minDigits(ns) <= suffixLen) {
                    answer = num.substr(0, i) + char('0' + dg) + buildSuffix(ns, suffixLen);
                    break;
                }
            }
            if (!answer.empty()) break;
        }

        if (!answer.empty()) return answer;

        // ---- Case B: longer number ----
        int L = max(n + 1, Lmin);
        return buildSuffix(target, L);
    }
};