//
//  knight-s-move.cpp
//  CodeSignal
//
//  Created by 차경준 on 05/06/2019.
//  Copyright © 2019 KyungJunCha. All rights reserved.
//
//  Problem URL : https://level.goorm.io/exam/43063/knight-s-move/quiz/1
//  Level : Medium

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

namespace knight_s_move {
    
    struct Knight
    {
        Knight(int x, int y, int s):xpos(x), ypos(y), step(s) {}
        int xpos;
        int ypos;
        int step;
    };
    
    void knight_s_move()
    {
        int move[8][2] = { {1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
        int height, width;
        
        cin >> height >> width;
        
        vector<vector<int>> board(height, vector<int>(width, -1));
        
        queue<Knight> q;
        
        q.push(Knight(0, 0 ,0));
        
        while(!q.empty())
        {
            Knight k = q.front(); q.pop();
            int xpos = k.xpos;
            int ypos = k.ypos;
            int step = k.step;
            
            if(board[xpos][ypos] > -1)
                continue;
            
            board[xpos][ypos] = step;
            step++;
            
            for(int i=0; i<8; i++)
            {
                int x = xpos + move[i][0];
                int y = ypos + move[i][1];
                
                if(0<=x && x<height && 0<=y && y<width)
                {
                    q.push(Knight(x, y, step));
                }
            }
        }
        
        bool full = true;
        int max_step = -1;
        
        for(int i=0; i<height; i++)
        {
            for(int j=0; j<width; j++)
            {
                if(board[i][j] == -1)
                    full = false;
                
                max_step = max(max_step, board[i][j]);
            }
        }
        
        cout << (full ? 'T':'F') << max_step;
    }
}


