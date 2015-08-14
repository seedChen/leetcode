/**
 * @file ans.cpp
 * @brief
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 *
 * @version
 * @date 2015-06-01 22:25
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
private:
    static bool cmp(const Interval& a, const Interval& b)
    {
        return a.start < b.start;
    }

    Interval doMerge(const Interval& a, const Interval& b)
    {
        if (a.end >= b.end)
            return a;
        else
            return Interval(a.start, b.end);
    }

public:
    vector<Interval> merge(vector<Interval>& intervals)
    {
        vector<Interval> result;
        if (intervals.size() == 0)
            return result;

        sort(intervals.begin(), intervals.end(), cmp);

        result.push_back(intervals[0]);
        for (int i = 1; i < (int)intervals.size(); ++i)
        {
            if (result.back().end >= intervals[i].start)
            {
                Interval next = doMerge(result.back(), intervals[i]);
                result.pop_back();
                result.push_back(next);
            }
            else
                result.push_back(intervals[i]);
        }

        return result;
    }
};

