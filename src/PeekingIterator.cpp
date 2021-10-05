#include <vector>
#include <stdlib.h>

using namespace std;

class Iterator
{
    struct Data;
    Data *data;

public:
    Iterator(const vector<int> &nums);
    Iterator(const Iterator &iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator
{
    struct Data {
        int index;
        const vector<int> nums;
    };
    Data* data;
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
        data = new Data{
            -1,
            nums
        };
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek()
    {
        return data->nums[data->index+1];
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next()
    {
        return data->nums[++data->index];
    }

    bool hasNext() const
    {
        return data->index + 1 < data->nums.size();
    }
};