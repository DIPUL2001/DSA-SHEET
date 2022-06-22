#define PI 3.14159265
#define MARGIN 1e-9

class Solution {
public:
    double get_angle(int x_diff, int y_diff) {
        return atan2(y_diff, x_diff) * 180 / PI;
    }
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int i, j, n = points.size(), common = 0;
        vector<double> vals;
        for(i=0; i<n; i++) {
            int x = points[i][0] - location[0];
            int y = points[i][1] - location[1];
            if(x == 0 && y == 0) {
                common++;
            }
            else {
                double A = get_angle(x, y);
                if(A < 0) A += 360;
                vals.emplace_back(A);
            }
        }

        sort(vals.begin(), vals.end());
        vector<double> a = vals;
        a.insert(a.end(), vals.begin(), vals.end());
        for(i=vals.size(); i<a.size(); i++)
            a[i] += 360;
        int ret = 0;
        for(i=0, j=0; i<a.size(); i++) {
            while(j < a.size() && (a[j]-a[i]<=angle + MARGIN))
                  j++;
            ret = max(ret, j - i);
        }
        return ret + common;
    }
};