#include <conio.h>
#include <windows.h>
#include <bits/stdc++.h>
#include <snake.h>
#include <tchar.h>
#include <strsafe.h>
int tmp;
bool init(snake &s){
	if(!kbhit())return true;
	tmp=getch();
	if(tmp==27)return false;
	s.turn((tmp!=224&&tmp!=0)?tmp:getch()+300);
	return true;
}
int main()
{
	flag:
	snake s(12,12);
	TCHAR ss[21];
	StringCchPrintf(ss,21,TEXT("snakes"));
	SetConsoleTitle(ss);
	system("mode con cols=15 lines=15");
    srand(time(NULL));
	s.print();
	while(s.move()){
		s.print();
		for(int i=1;i<=10;i++){
			Sleep(10);
			if(!init(s)){
				puts("You Exited");
				getch();
				return 0;
			}
		}
	}
	puts("Game Over");
	if(getch()!=27)goto flag;
	/*
	up 0 72
	down 0 80
	left 0 75
	right 0 77
	esc 27
	*/
	return 0;
}