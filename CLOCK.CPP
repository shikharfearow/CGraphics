#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<time.h>
void main(){
	int gd=DETECT, gm;
	struct tm *timeStruct;
	time_t seconds;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	while(!kbhit()){
	seconds = time(NULL);
	timeStruct = localtime(&seconds);
	int hr = timeStruct->tm_hour;
	int min = timeStruct->tm_min;
	int sec = timeStruct->tm_sec;
	if(hr>=12){
		hr=hr-12;
	}
	circle(getmaxx()/2,getmaxy()/2,150);
	pieslice(getmaxx()/2,getmaxy()/2,91-(hr*30),90-(hr*30),50);
	pieslice(getmaxx()/2,getmaxy()/2,91-(min*6),90-(min*6),75);
	pieslice(getmaxx()/2,getmaxy()/2,91-(sec*6),90-(sec*6),100);
	delay(1000);
	cleardevice();
	}
	getch();
}