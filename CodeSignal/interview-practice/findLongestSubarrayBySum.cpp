//
//  findLongestSubarrayBySum.cpp
//  CodeSignal
//
//  Created by 차경준 on 21/08/2019.
//  Copyright © 2019 KyungJunCha. All rights reserved.
//
//  Problem URL : https://app.codesignal.com/interview-practice/task/izLStwkDr5sMS9CEm/description?solutionId=93GxhAeZ9YHeaNFEn
//  Difficulty : Medium
//  Time Complex Prediction : Best Case O(n), Worst Case O(n2)
//  Note : iterator

#include "interview-practice.h"

#include <numeric>

std::vector<int> findLongestSubarrayBySum(int s, std::vector<int> arr)
{
    std::vector<int> answer;
    
    std::vector<int>::iterator l_bound;
    int length = -1;
    
    std::vector<int>::iterator l = arr.begin();
    std::vector<int>::iterator r = l;
    int sum = 0;
    
    while(l<=r && r<=arr.end())
    {
        
        if(sum == s)
        {
            if(length < distance(l,r))
            {
                l_bound = l;
                length = distance(l,r);
            }
            
            sum += *r;
            r++;
        }
        else if(sum > s)
        {
            sum -= *l;
            l++;
        }
        else
        {
            sum += *r;
            r++;
        }
    }
    
    if(length == -1)
    {
        answer.push_back(-1);
    }
    else
    {
        answer.push_back(distance(arr.begin(), l_bound) + 1);
        answer.push_back(distance(arr.begin(), l_bound) + length);
    }
    
    return answer;
}
