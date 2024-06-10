#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// langauge: c++, using map of occurences of elements solve this problem..

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;
        vector<int>freq(101,0);

        for (int val: heights) freq[val]++;

        int i=0, j=0;

        while (i < 101){
            if (freq[i] == 0) i++;
            else{
                if (heights[j] != i){
                    count++;
                }
                freq[i]--;
                j++;
            }
        }

        return count;
    }
};

/*

Langauge: c++

using : sorting with counter tecqunice..

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;
        vector<int>expected = heights;
        sort(expected.begin(), expected.end());
        for (int i=0; i<heights.size(); i++) if (expected[i] != heights[i]) count++;
        return count;
    }
};

*/

/*
Language: C

we can solve it by using to approach by bobble sort or quick sort according to the constraints...

int heightChecker(int* heights, int heightsSize){
    int* expected = (int*)malloc(heightsSize*sizeof(int));
    int ans = 0;
    for (int i = 0; i < heightsSize; i++){
        expected[i] = heights[i];
    }
    for (int i = 0; i < heightsSize; i++){
        for (int j = i+1; j < heightsSize; j++){
            if (expected[i] > expected[j]){
                int temp = expected[i];
                expected[i] = expected[j];
                expected[j] = temp;
            }
        }
    }
    for (int i = 0; i < heightsSize; i++){
        if (expected[i] != heights[i])
        ans++;
    }
    return ans;

}

*/