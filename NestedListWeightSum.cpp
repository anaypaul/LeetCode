/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int helper(vector<NestedInteger>& nestedList, int pos,int len,  int depth){
        int sum = 0;
        for(int i = 0;i<len;i++){
            if(nestedList[i].isInteger()){
                sum += nestedList[i].getInteger() * depth ;
            }else{
                int len_x = nestedList[i].getList().size();
                sum += helper(nestedList[i].getList(), 0, len_x, depth+1);
            }
        }
        return sum;
    }
    int depthSum(vector<NestedInteger>& nestedList) {
        return helper(nestedList,0,nestedList.size(), 1);
    }
};