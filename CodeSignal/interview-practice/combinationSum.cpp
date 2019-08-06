//
//  mostFrequentSum.cpp
//  CodeSignal
//
//  Created by 차경준 on 06/08/2019.
//  Copyright © 2019 KyungJunCha. All rights reserved.
//
//  Problem URL : https://app.codesignal.com/interview-practice/task/JAhrxhDQDLDDA3NXe
//  Difficulty : Hard
//  Note : BackTracking
#include "interview-practice.h"

namespace combinationSum
{
    struct compare
    {
        bool operator()(std::vector<int> lv, std::vector<int> rv) const
        {
            for(int i=0; i<lv.size(); i++)
            {
                if(lv[i] == rv[i])
                    continue;
                return lv[i] < rv[i];
            }
            return true;
        }
    }my_compare;
    
    std::string combinationSum(std::vector<int> a, int sum)
    {
        vector<vector<int>> answer;
        sort(a.begin(), a.end(), greater<int>());
        vector<int>::iterator it = std::unique(a.begin(), a.end());
        a.resize(distance(a.begin(), it));
        
        stack<vector<int>> s;
        
        for(int i=0; i<a.size(); i++)
        {
            s.push(vector<int>(1, a[i]));
        }
        
        while(!s.empty())
        {
            vector<int> cur = s.top(); s.pop();
            int b = cur.back();
            
            int cur_sum = accumulate(cur.begin(), cur.end(), 0);
            
            if(cur_sum == sum)
            {
                sort(cur.begin(), cur.end());
                answer.push_back(cur);
                continue;
            }
            else if(cur_sum > sum)
                continue;
            
            for(int i=0; i<a.size(); i++)
            {
                if(a[i]<=b && (a[i]+cur_sum)<=sum)
                {
                    vector<int> tmp(cur);
                    tmp.push_back(a[i]);
                    s.push(tmp);
                }
            }
            
        }
        
        sort(answer.begin(), answer.end(), my_compare);
        
        string answer_string = "";
        
        for(int i=0; i<answer.size(); i++)
        {
            answer_string += "\(";
            for(int j=0; j<answer[i].size(); j++)
            {
                answer_string += to_string(answer[i][j]);
                
                if(j != answer[i].size()-1)
                    answer_string += " ";
            }
            answer_string += "\)";
        }
        
        return answer_string.empty() ? "Empty":answer_string;
    }
}
