/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
    long long cross(int x1,int y1,int x2,int y2){
        return (long long)x1*y2-(long long)x2*y1;
    }
public:
    int maxPoints(vector<Point>& points) {
        int m=0;
        for(int i=0;i<points.size();++i){
            int cnt=0;
            for(int j=0;j<points.size();++j)
                if(points[i].x==points[j].x&&points[i].y==points[j].y)
                    ++cnt;
            if(cnt>m)m=cnt;
        }
        for(int i=0;i<points.size();++i){
            for(int j=i+1;j<points.size();++j){
                if(points[i].x==points[j].x&&points[i].y==points[j].y)continue;
                int cnt=0;
                for(int k=0;k<points.size();++k)
                    if(cross(points[i].x-points[j].x,points[i].y-points[j].y,points[i].x-points[k].x,points[i].y-points[k].y)==0)
                        ++cnt;
                if(cnt>m)m=cnt;
            }
        }
        return m;
    }
};
