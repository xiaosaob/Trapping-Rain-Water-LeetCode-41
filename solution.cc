// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

// For example, 
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

class Solution {
public:
    int trap(int A[], int n) {
        stack<int> myStack;
        int res = 0;
        for(int i = 0; i < n; ++i) {
            if(myStack.empty() || A[i] <= A[myStack.top()])
                myStack.push(i);
            else {
                while(!myStack.empty() && A[i] > A[myStack.top()]) {
                    int bottom = A[myStack.top()];
                    myStack.pop();
                    if(!myStack.empty()) {
                        res += (min(A[i], A[myStack.top()])-bottom)*(i-1-myStack.top());
                    }
                }
                myStack.push(i);
            }
        }
        return res;
    }
};
