#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<iostream.h>
#include<math.h>
union REGS in,out;
int x,y,cl,color = 0;
void canvas(){
	for(int i=0;i<16;i++){
		setfillstyle(SOLID_FILL,i);
		rectangle(10,20+i*20,20,30+i*20);
		floodfill(11,21+i*20,15);
	}
	outtextxy(30,10,"FREE HAND");
	outtextxy(130,10,"LINE");
	outtextxy(230,10,"SQUARE/RECTANGLE");
	outtextxy(430,10,"CIRCLE");
}

void hidemouse(){
	in.x.ax = 2;
	int86(0x33,&in,&out);
}

void showpointer(){
	in.x.ax = 1;
	int86(0x33,&in,&out);
}

void mouseclick(int &x,int &y,int &click){
	in.x.ax = 3;
	int86(0x33,&in,&out);
	x = out.x.cx;
	y = out.x.dx;
	click = out.x.bx;
}

void freehand(){
	while(1){
		if(cl == 2){
			break;
		}
		mouseclick(x,y,cl);
		if(cl==1){
			hidemouse();
			putpixel(x,y,color);
		}
		showpointer();
	}
}

void line(){
	int x1,y1,x2,y2,flag=0;
	setwritemode(XOR_PUT);
	setcolor(color);
	while(!kbhit()){
		mouseclick(x,y,cl);
		x1=x;
		y1=y;
		while(cl==1){
			hidemouse();
			if(y1>25){
			line(x1,y1,x,y);
			}
			mouseclick(x,y,cl);
			hidemouse();
			x2=x;
			y2=y;
			line(x1,y1,x2,y2);
		}
		if(cl==2){
			break;
		}
		showpointer();
	}
	setwritemode(COPY_PUT);
}


void square(){
	int x1,y1,x2,y2;
	while(!kbhit()){
		mouseclick(x,y,cl);
		if(cl==1){
			hidemouse();
			x1=x;
			y1=y;
		}
		if(cl==2){
			x2=x;
			y2=y;
			setcolor(color);
			rectangle(x1,y1,x2,y2);
		}
		showpointer();
	}

}

void circle(){
	int x1,y1,x2,y2;
	while(!kbhit()){
		mouseclick(x,y,cl);
		if(cl==1){
			hidemouse();
			x1=x;
			y1=y;
		}
		if(cl==2){
			x2=x;
			y2=y;
			int cx = (x1+x2)/2;
			int cy = (y1+y2)/2;
			rectangle(x1,y1,x2,y2);
			setcolor(color);
			ellipse(cx,cy,0,360,(x2-x1)/2,(y2-y1)/2);
		}
		showpointer();
	}

}

void clickEvent(){
	if(x>30 && x<130 && y >= 10 && y<20){
		freehand();
	}
	else if(x>130 && x<230 && y >= 10 && y<30){
		line();
	}
	else if(x>230 && x<430 && y >= 10 && y<30){
		square();
	}
	else if(x>430 && x<530 && y >= 10 && y<30){
		circle();
	}
	else if(x>10 && x<20 && y>20 && y<30){
		color = 0;
	}
	else if(x>10 && x<20 && y>40 && y<50){
		color=1;
	}
	else if(x>10 && x<20 && y>60 && y<70){
		color=2;
	}
	else if(x>10 && x<20 && y>80 && y<90){
		color=3;
	}
	else if(x>10 && x<20 && y>100 && y<110){
		color=4;
	}
	else if(x>10 && x<20 && y>120 && y<130){
		color=5;
	}
	else if(x>10 && x<20 && y>140 && y<150){
		color=6;
	}
}

void main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	canvas();
	showpointer();
	do{
	mouseclick(x,y,cl);
	if(cl==1){
		clickEvent();
	}
	}while(!kbhit());
	getch();
}