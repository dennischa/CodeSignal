//
//  arrayMaxConsecutiveSum2.cpp
//  CodeSignal
//
//  Created by 차경준 on 06/08/2019.
//  Copyright © 2019 KyungJunCha. All rights reserved.
//
//  Problem URL : https://app.codesignal.com/interview-practice/task/dQD4TCunke2JQ98rj
//  Difficulty : Easy
// Time Complex Prediction : O(n)
#include "interview-practice.h"

namespace arrayMaxConsecutiveSum2
{
    int arrayMaxConsecutiveSum2(std::vector<int> inputArray)
    {
        int right_end_max = inputArray.front();
        int array_max = inputArray.front();
        
        for(int i=1; i<inputArray.size();i++)
        {
            right_end_max = max(right_end_max+inputArray[i], inputArray[i]);
            array_max = max(array_max, right_end_max);
        }
        
        return array_max;
    }
}
