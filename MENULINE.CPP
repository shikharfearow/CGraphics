#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>

void brasenhamdraw(){
	int x0,y0,x1,y1;
	int dx,dy,p,x,y;
	printf("Enter co-ordinates of first point:");
	scanf("%d%d",&x0,&y0);
	printf("Enter co-ordinates of second point: ");
	scanf("%d%d",&x1,&y1);
	cleardevice();
	dx = x1-x0;
	dy = y1-y0;
	x = x0;
	y = y0;
	p = 2*dy - dx;



	while( x<x1 ){
		if(p>=0){
			putpixel(x,y,7);
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
		{
			putpixel(x,y,7);
			p=p+2*dy;
		}
		x = x+1;
	}
}

void drawdda(){
	float x,y,dx,dy,steps;
	int x0,x1,y0,y1,i;

	printf("Enter co-ordinates of first point:");
	scanf("%d%d",&x0,&y0);
	printf("Enter co-ordinates of second point: ");
	scanf("%d%d",&x1,&y1);
	cleardevice();
	dx = (float)x1-x0;
	dy = (float)y1-y0;
	if(dx>=dy){
		steps=dx;
	}
	else{
		steps=dy;
	}
	dx = dx/steps;
	dy = dy/steps;
	x=x0;
	y=y0;
	i=1;
	while(i<= steps){
		putpixel(x,y,GREEN);
		x+=dx;
		y+=dy;
		i++;
	}
}

void main(){
	int choice,gdriver = DETECT, gmode, error, x0, y0, x1, y1;
	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\bgi");
	cout<<"1. DDA Line Drawing Algorithm"<<endl;
	cout<<"2. Brasenham Line Drawing Algorithm"<<endl;
	cout<<"Choose your line drawing algorithm:"<<endl;
	cin>>choice;

	switch(choice){
		case 1:
			drawdda();
			break;
		case 2:
			brasenhamdraw();
			break;
		default:
		cout<<"Wrong value";
	}
	getch();
}






