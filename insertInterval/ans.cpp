/**
 * @file ans.cpp
 * @brief
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their
 * start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as
 * [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 *
 * @version
 * @date 2015-06-03 09:57
 * @author chen_juntao
 * @email chen_juntao@outlook.com
 */

#include <vector>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
private:
    Interval doMerge(const Interval& a, const Interval& b)
    {
        if (a.end >= b.end)
            return a;
        else
            return Interval(a.start, b.end);
    }

public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
    {
        vector<Interval> result;
        if (intervals.size() == 0)
        {
            result.push_back(newInterval);
            return result;
        }

        if (newInterval.end < intervals[0].start)
        {
            result.push_back(newInterval);
            for (int i = 0; i < (int)intervals.size(); i++)
                result.push_back(intervals[i]);
            return result;
        }

        if (newInterval.start > intervals[intervals.size() - 1].end)
        {
            for (int i = 0; i < (int)intervals.size(); i++)
                result.push_back(intervals[i]);
            result.push_back(newInterval);
            return result;
        }

        int i = 0;
        for (; i < (int)intervals.size(); i++)
        {
            if (intervals[i].end < newInterval.start)
                result.push_back(intervals[i]);
            else
            {
                break;
            }
        }

        if (intervals[i].start > newInterval.end)
        {
            result.push_back(newInterval);
            result.push_back(intervals[i]);
            i++;
        }
        else
        {
            if (intervals[i].start >= newInterval.start)
            {
                Interval next = doMerge(newInterval, intervals[i]);
                result.push_back(next);
                i++;
            }
            else
            {
                Interval next = doMerge(intervals[i], newInterval);
                result.push_back(next);
                i++;
            }
        }

        for (; i < (int)intervals.size(); i++)
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

