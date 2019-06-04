//
//  feedingTime.cpp
//  CodeSignal
//  Problem URL : https://app.codesignal.com/interview-practice/task/bdatSZvuKFyjJ8eYw
//  Created by 차경준 on 03/06/2019.
//  Copyright © 2019 KyungJunCha. All rights reserved.
//


#include "interview-practice.h"

using namespace std;

namespace feedingTime {
    
    struct ColoringGraph
    {
        ColoringGraph(int n, vector<int> c, map<int, bool> m):num(n), colors(c), usedColors(m) {}
        int num;
        vector<int> colors;
        map<int, bool> usedColors;
        
        int getUsedColorsCount() const
        {
            return (int)usedColors.size();
        }
        
        void useColor(int color)
        {
            colors[num] = color;
            usedColors[color] = true;
        }
    };
    
    vector<vector<int>> makeAdjacencyArray(const vector<vector<string>>& classes)
    {
        const auto size = classes.size();
        vector<vector<int>> arr(size, vector<int>(size, 0));
        
        for(int i=0; i<size; i++)
        {
            const vector<string>& u = classes.at(i);
            
            for(int j=0; j<size; j++)
            {
                const vector<string>& v = classes.at(j);
                
                for(int z=0; z<u.size(); z++)
                {
                    const string& s = u.at(z);
                    
                    if(find(v.begin(), v.end(), s) != v.end())
                    {
                        arr[i][j] = 1;
                        break;
                    }
                }
            }
        }
        
        return arr;
    }
    
    bool isViable(const ColoringGraph& g, const vector<vector<int>> &adjArr, int count)
    {
        const int& num = g.num;
        const vector<int>& colors = g.colors;
        
        if(g.getUsedColorsCount() > count)
            return false;
        
        for(int i=0; i<num; i++)
        {
            if(adjArr[i][num] == 1 && colors[i] == colors[num])
            {
                return false;
            }
        }
        
        return true;
    }
    
    int feedingTime(vector<vector<string>> classes)
    {
        auto size = classes.size();
        vector<vector<int>> adjArr = makeAdjacencyArray(classes);
        vector<int> colors(size, -1);
        
        stack<ColoringGraph> s;
        
        ColoringGraph cg(0, colors, map<int, bool>());
        cg.useColor(0);
        
        s.push(cg);
        
        int answer = 6;
        
        while(!s.empty())
        {
            ColoringGraph sub = s.top(); s.pop();
            
            if(sub.num == size-1)
            {
                answer = min(answer, sub.getUsedColorsCount());
                continue;
            }
            
            int num = sub.num + 1;
            
            for(int i=0; i<5; i++)
            {
                int color = i;
                
                ColoringGraph tmp(num, sub.colors, sub.usedColors);
                tmp.useColor(color);
                
                if(isViable(tmp, adjArr, answer))
                {
                    s.push(tmp);
                }
            }
        }
        
        return answer > 5 ? -1 : answer;
    }
}
