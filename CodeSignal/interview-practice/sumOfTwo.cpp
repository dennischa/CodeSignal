//
//  sumOfTwo.cpp
//  CodeSignal
//
//  Created by 차경준 on 30/06/2019.
//  Copyright © 2019 KyungJunCha. All rights reserved.
//
//  Problem URL : https://app.codesignal.com/interview-practice/task/Hm98RnqK9Be575yoj
//  Difficulty : Easy
//  Note : Sort, Iterator

#include "interview-practice.h"

namespace commonTechniquesBasic{
    bool sumOfTwo(std::vector<int> a, std::vector<int> b, int v)
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        
        vector<int>::iterator aIt = a.begin();
        vector<int>::iterator bIt = b.begin();
        
        while(aIt != a.end() && bIt != b.end())
        {
            int sum = *aIt + *bIt;
            
            if(sum == v)
                return true;
            else if (sum < v)
                aIt++;
            else
                bIt++;
        }
        
        return false;
    }
}
