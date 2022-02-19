#include<conio.h>
#include<bits/stdc++.h>
#include<snake.h>
void snake::make_food(){
    int x=(abs(rand())%10)+2,y=(abs(rand())%10)+2;
    while(room[x][y]||(x==foodx&&y==foody)){
        x=(abs(rand())%10)+2,y=(abs(rand())%10)+2;
    }
    foody=y,foodx=x;
}
snake::snake(int x,int y){
    srand(time(NULL));
    memset(room,false,sizeof(room));
    to.clear();score=0;
    while(!q.empty())q.pop();
	for(int i=1;i<=y||i<=x;i++)room[1][i]=room[y][i]=room[i][1]=room[i][x]=true;
    q.push(make_pair(5,10)),room[5][10]=true;
    q.push(make_pair(5,9)),room[5][9]=true;
    q.push(make_pair(5,8)),room[5][8]=true;
    to['W']=to['w']=to[372]=1,to['a']=to['A']=to[375]=2,to['S']=to['s']=to[380]=3,to['d']=to['D']=to[377]=4;
    last_side=next_side=2;
    make_food();
}
void snake::turn(int new_side){
    if(to[new_side]&&((to[new_side]^last_side)&1))next_side=to[new_side];
}
void snake::del_back(){
    room[q.front().first][q.front().second]=false;
    q.pop();
}
bool snake::new_front(){
    q.push(make_pair(q.back().first+dx[last_side],q.back().second+dy[last_side]));
    if(!room[q.back().first][q.back().second])return room[q.back().first][q.back().second]=true;
    return false;
}
bool snake::move(){
    last_side=next_side;
    if(q.back().first+dx[last_side]!=foodx||q.back().second+dy[last_side]!=foody)del_back();
    else score+=10,make_food();
    return new_front();
}
void snake::print(){
    char s[21][14];
    for(int i=1;i<=12;i++){
        for(int j=1;j<=12;j++){
            if(i==foodx&&j==foody)s[i][j]='@';
            else if(!room[i][j])s[i][j]=' ';
            else if(i==1||i==12||j==1||j==12)s[i][j]='#';
            else if(i!=q.back().first||j!=q.back().second)s[i][j]='0';
            else s[i][j]='O';
        }
    }
    system("cls");
    printf("score:%d\n",score);
    for(int i=1;i<=12;i++){
        for(int j=1;j<=12;j++){
            putchar(s[i][j]);
        }
        puts("");
    }
}