//
//  sumInRange.cpp
//  CodeSignal
//
//  Created by 차경준 on 06/08/2019.
//  Copyright © 2019 KyungJunCha. All rights reserved.
//
//  Problem URL : https://app.codesignal.com/interview-practice/task/4MoqQLaw22nrzXbgs
//  Difficulty : Medium
// Time Complex Prediction : O(n)
//  Note : DynamicProgramming
#include "interview-practice.h"

namespace sumInRange {
    int sumInRange(std::vector<int> nums, std::vector<std::vector<int>> queries)
    {
        long answer = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(i-1>=0)
                nums[i] = nums[i-1] + nums[i];
        }
        
        for(int i=0; i<queries.size(); i++)
        {
            int& from = queries[i][0];
            int& to = queries[i][1];
            
            answer += nums[to] - (from < 1 ? 0 : nums[from-1]);
        }
        
        answer %= 1000000007;
        
        if(answer<0)
            answer = 1000000007 + answer;
        
        return answer;
    }

}
