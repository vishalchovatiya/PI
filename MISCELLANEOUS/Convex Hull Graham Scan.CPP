#include "utils.hpp"
#include <iostream>
#include <cmath> // atan2
#include <stack>

struct point {
    float x;
    float y;
};

ostream &operator<<(ostream &os, const point &obj) {
    os << "(" << obj.x << ", " << obj.y << ")";
    return os;
}

// Find counter clock-wise angle based on given 3 points
// See https://www.geeksforgeeks.org/orientation-3-ordered-points/
// for details of below formula.
bool ccw(const point &a, const point &b, const point &c) {
    float area = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);

    if (area > 0) return true;  // counter clock-wise
    if (area < 0) return false; // clock-wise
    return false;               // collinear
}

//  for details https://youtu.be/SBdWdT_5isI
vector<point> convex_hull_graham_scan(vector<point> points) {
    vector<point>   hull;

    auto last = [&hull]() { return *rbegin(hull); };
    auto before_last = [&hull]() { return *(rbegin(hull)+1); };

    auto by_angle = [](auto p1, auto p2) { return atan2(p1.y, p1.x) < atan2(p2.y, p2.x); };
    sort(ALL(points), by_angle);

    for (size_t i = 0; i < points.size(); i++) {
        while(hull.size() >=2 and ccw(before_last(), last(), points[i])){
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    
    return hull;
}

int main() {
    vector<point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                            {0, 0}, {1, 2}, {3, 1}, {3, 3}};

    DEBUG(convex_hull_graham_scan(points));

    // DEBUG(atan2(10, 10));

    return 0;
}
