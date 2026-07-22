from typing import List

class Solution:
    def maxActiveSectionsAfterTrade(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        totalOnes = s.count('1')

        # ---- run length encode ----
        runStart, runEnd, runChar = [], [], []
        i = 0
        while i < n:
            j = i
            while j < n and s[j] == s[i]:
                j += 1
            runStart.append(i); runEnd.append(j - 1); runChar.append(s[i])
            i = j
        m = len(runStart)
        runLen = [runEnd[k] - runStart[k] + 1 for k in range(m)]

        runOf = [0] * n
        for k in range(m):
            for p in range(runStart[k], runEnd[k] + 1):
                runOf[p] = k

        NEG = -10**9
        POS = 10**9

        min1Arr = [runLen[k] if runChar[k] == '1' else POS for k in range(m)]
        max0Arr = [runLen[k] if runChar[k] == '0' else NEG for k in range(m)]
        P = [NEG] * m
        for k in range(1, m - 1):
            if runChar[k] == '1':
                P[k] = runLen[k - 1] + runLen[k + 1]

        # ---- sparse tables (static array, O(1) range max/min) ----
        LOG = [0] * (m + 2)
        for x in range(2, m + 2):
            LOG[x] = LOG[x // 2] + 1

        def build(arr, cmp):
            if m == 0:
                return []
            K = LOG[m] + 1
            st = [arr[:]]
            for j in range(1, K):
                half = 1 << (j - 1)
                length = 1 << j
                prev = st[-1]
                limit = m - length + 1
                if limit <= 0:
                    break
                row = [cmp(prev[idx], prev[idx + half]) for idx in range(limit)]
                st.append(row)
            return st

        st_min1 = build(min1Arr, min)
        st_max0 = build(max0Arr, max)
        st_P = build(P, max)

        def q_min(st, l, r):
            if l > r:
                return POS
            k = LOG[r - l + 1]
            return min(st[k][l], st[k][r - (1 << k) + 1])

        def q_max(st, l, r):
            if l > r:
                return NEG
            k = LOG[r - l + 1]
            return max(st[k][l], st[k][r - (1 << k) + 1])

        ans = []
        for l, r in queries:
            a = runOf[l]
            b = runOf[r]
            if a == b:
                ans.append(totalOnes)
                continue

            La = runEnd[a] - l + 1
            Lb = r - runStart[b] + 1

            if a + 1 <= b - 1:
                min1 = q_min(st_min1, a + 1, b - 1)
                max0mid = q_max(st_max0, a + 1, b - 1)
            else:
                min1 = POS
                max0mid = NEG

            globalMax0 = max0mid
            if runChar[a] == '0':
                globalMax0 = max(globalMax0, La)
            if runChar[b] == '0':
                globalMax0 = max(globalMax0, Lb)

            bestMerge = NEG
            if a + 2 <= b - 2:
                bestMerge = q_max(st_P, a + 2, b - 2)

            # special: i = a+1
            if a + 1 <= b - 1 and runChar[a + 1] == '1':
                left = La
                if a + 1 == b - 1:
                    right = Lb
                else:
                    right = runLen[a + 2]
                bestMerge = max(bestMerge, left + right)

            # special: i = b-1 (only if distinct from a+1)
            if b - 1 >= a + 1 and runChar[b - 1] == '1' and (b - 1) != (a + 1):
                right = Lb
                left = runLen[b - 2]
                bestMerge = max(bestMerge, left + right)

            bonus_candidate = NEG
            if min1 < POS:
                bonus_candidate = globalMax0 - min1

            bonus = max(0, bestMerge, bonus_candidate)
            ans.append(totalOnes + bonus)

        return ans