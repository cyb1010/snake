#include<bits/stdc++.h>
using namespace std;
class snake{
    private:
        queue<pair<int,int>>q;
        unordered_map<int,int>to;
        int dx[5]={0,-1,0,1,0},dy[5]={0,0,-1,0,1};
        int last_side,next_side,foodx,foody,score;
        bool room[110][110];
        void del_back();
        bool new_front();
        void make_food();
    public:
        snake(int x,int y);
        bool move();
        void turn(int side);
        void print();
};