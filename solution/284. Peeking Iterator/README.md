# 284. Peeking Iterator

## Solution 1: 預先保存 next 的值

```cpp
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *        struct Data;
 *         Data* data;
 *        Iterator(const vector<int>& nums);
 *         Iterator(const Iterator& iter);
 *
 *         // Returns the next element in the iteration.
 *        int next();
 *
 *        // Returns true if the iteration has more elements.
 *        bool hasNext() const;
 *    };
 */

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        hasNext_ = Iterator::hasNext();
        if (hasNext_) val_ = Iterator::next();
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return val_;
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int tmp = val_;
        hasNext_ = Iterator::hasNext();
        if (hasNext_) val_ = Iterator::next();
        return tmp;
    }
    
    bool hasNext() const {
        return hasNext_;
    }
    
private:
    int val_;
    bool hasNext_;
};

```

## Solution 2: 每次 peek 時複製

每次 peek 時複製 Iterator - ```Iterator(*this)```，並取走它的 next。

```cpp
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *        struct Data;
 *         Data* data;
 *        Iterator(const vector<int>& nums);
 *         Iterator(const Iterator& iter);
 *
 *         // Returns the next element in the iteration.
 *        int next();
 *
 *        // Returns true if the iteration has more elements.
 *        bool hasNext() const;
 *    };
 */

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return Iterator(*this).next();
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        return Iterator::next();
    }
    
    bool hasNext() const {
        return Iterator::hasNext();
    }
};

```
