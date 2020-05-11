/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        map <pair<double,double>,int> u;
        int ans = 0;
        int x1,y1,x2,y2;
        if(points.size()<=1){
            return points.size();
        }
        sort(points.begin(),points.end());
        double m,pt;
        int n = points.size();
        for (int i=0;i<n;i++){
            x1 = points[i][0];
            y1 = points[i][1];
            int power = 0;
            while(i<n-1 && x1 == points[i+1][0] && y1 == points[i+1][1]){
                power++;
                i++;
                cout << "i increased to " << i << " and power = " <<power;
            }
            ans = max(ans,power);
            for(int j=i+1 ;j<n;j++){
                x2 = points[j][0];
                y2 = points[j][1];
                m = (x2-x1);
                if(y2-y1 == 0){
                    m = 0.001;
                }else{
                m = m/(y2-y1);
                }
                pt = y1; 
                pt -= m* x1;
                cout << i << ' '<< j <<' '<< m << ' '<<pt << endl;
                auto it = u.find({m,pt});
                if(it == u.end()){
                    u[{m,pt}] = 0;                   
                }
                u[{m,pt}] = u[{m,pt}] +1;
                ans = max(ans,u[{m,pt}]+power);
            }
            u.clear();
        }
        return ans+1;
    }
};
// @lc code=end
