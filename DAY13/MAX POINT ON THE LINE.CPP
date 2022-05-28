#include <iostream>
#include <map>
#include <algorithm>

struct Line 
{
    float k;
    float b;
};

inline bool lessFloat(float a, float b) 
{
    return (b - a) > ( (fabs(a) < fabs(b) ? abs(b) : fabs(a)) * 0.0001f);
}

template<> struct less<Line>
{
    bool operator() (const Line& lhs, const Line& rhs) const
    {
        if (not lessFloat(lhs.k, rhs.k) and not lessFloat(rhs.k, lhs.k)) {
            return lessFloat(lhs.b, rhs.b);
        } else {
            return lessFloat(lhs.k, rhs.k);
        }
    }
};

using Lines = std::map<Line, int>;

Line makeLine(const vector<int>& lhs, const vector<int>& rhs)
{
    Line result;
    // x1 == x2
    if (lhs[0] == rhs[0]) {
        result.k = std::numeric_limits<float>::infinity();
        result.b = lhs[0]; // == x
    } else {
        // k = (y2 - y1) / (x2 - x1)
        result.k = (rhs[1] - lhs[1]) / float(rhs[0] - lhs[0]);
        // y1 - k * x1
        result.b = lhs[1] - result.k * lhs[0];        
    }
    return result;
}

int maxPointsLine(const vector<vector<int>>& points) {
    if (points.size() == 1) {
        return 1;
    }
        
    Lines lines;
    auto max = 1;
    for (std::size_t i=0; i<points.size()-1; ++i) {
        for (std::size_t j=i+1; j<points.size(); ++j) {
            auto line = makeLine(points[i], points[j]);
            
            auto lineIt = lines.find(line);
            if (lineIt == lines.end()) {
                lines.emplace(line, 1);
            } else {
                ++(lineIt->second);
                if (lineIt->second > max) {
                    max = lineIt->second;
                }
            }
            
        }       
    }
    
    // x = (1 + sqrt(1 + 8 * pairs)) / 2
    return (1 + pow(1 + 8 * max, 0.5)) / 2;
}

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        return maxPointsLine(points);
    }
};