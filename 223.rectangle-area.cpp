/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 */

// @lc code=start
class Solution
{
public:
    bool inside(int A, int B, int C, int D, int E, int F)
    {
        if (E <= C && F <= D && E >= A && F >= B)
            return true;
        return false;
    }
    bool intersect(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        if (inside(A, B, C, D, E, F))
            return true;
        if (inside(A, B, C, D, E, H))
            return true;
        if (inside(A, B, C, D, G, H))
            return true;
        if (inside(A, B, C, D, G, F))
            return true;
        if (inside(E, F, G, H, A, B))
            return true;
        if (inside(E, F, G, H, A, D))
            return true;
        if (inside(E, F, G, H, C, D))
            return true;
        if (inside(E, F, G, H, C, B))
            return true;
        if (A < min(E, G) && C > max(E, G) && B > min(F, H) && D < max(F, H))
        {
            cout << "from condition 2" << endl;
            return true;
        }
        return false;
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        if (A == E && B == F && C == G && D == H)
            return ((D - B) * (C - A));
        int ans = ((D - B) * (C - A)) + ((H - F) * (G - E));
        cout << ((D - B) * (C - A)) << " + " << ((H - F) * (G - E)) << " = " << ans << endl;
        if (intersect(A, B, C, D, E, F, G, H) || intersect(E,F,G,H,A,B,C,D))
        {
            ans -= (min(D, H) - max(B, F)) * (min(C, G) - max(A, E));
            cout << " - " << (min(D, H) - max(B, F)) * (min(C, G) - max(A, E)) << " = " << ans << endl;
        }
        return ans;
    }
};
// @lc code=end
