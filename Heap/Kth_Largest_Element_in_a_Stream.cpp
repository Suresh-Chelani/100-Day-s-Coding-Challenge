class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> mnHeap;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (auto &val: nums){
            add(val);
        }
    }
    
    int add(int val) {
        mnHeap.push(val);

        if (mnHeap.size() > K) mnHeap.pop();

        return mnHeap.top();
    }
};



/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

//  [4, 5, 8, 2]

// 2 3 4 5 8 return 4;

// 2 3 4 5 5 8 return 5;

// 2 3 4 5 5 8 10 return 10;

// 2 3 4 5 5 8 9 10 return 8

// 2 3 4 4 5 5 8 9 10 return 8

// -3 -2 return -3;

// -3 -2 0 return -2;
