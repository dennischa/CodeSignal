//
//  minSubstringWithAllChars.cpp
//  CodeSignal
//
//  Created by 차경준 on 21/08/2019.
//  Copyright © 2019 KyungJunCha. All rights reserved.
//
//  Problem URL : https://app.codesignal.com/interview-practice/task/rFeSD5rNy9RxfLcqg/solutions
//  Difficulty : Easy
//  Time Complex Prediction : O(n2)
//  Note : std::set

#include "interview-practice.h"

#include <set>

std::string minSubstringWithAllChars(std::string s, std::string t)
{
    if(t.empty())
        return "";
    
    const std::set<char> t_set(t.begin(), t.end());
    int start = 0;
    size_t size = s.size();
    
    for(int i=0; i<s.size(); i++)
    {
        if(t.find(s[i]) == std::string::npos)
            continue;
        
        std::set<char> tmp(t_set);
        
        for(int j=i; j<s.size(); j++)
        {
            tmp.erase(s[j]);
            
            if(tmp.empty())
            {
                if(j-i+1<size)
                {
                    size = j-i+1;
                    start = i;
                    break;
                }
            }
        }
        
    }
    
    return s.substr(start, size);
}

