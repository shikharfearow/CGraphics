#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<time.h>
#include<iostream.h>

int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
int pos=15;

void shuffle(int a[]){
	int r,t;
	srand(unsigned(time(0)));
	for(int i=0;i<15;i++){
		r = (rand()%15);
		t = a[i];
		a[i] = a[r];
		a[r] = t;
	}
}

/*int checkSolvable(int a[]){
	int countInversion=0;
	for(int i=0;i<15;i++){
		if(a[i]>a[i+1]){
			countInversion++;
		}
	}
	if(countInversion%2 == 0){
		return 1;
	}
	return 0;
}*/

void genpuzzle(){
	cleardevice();
	rectangle(80,100,400,420);
	char buffer[2];
	for(int i=0;i<4;i++){
		settextstyle(1,0,1);
		//row 1
		if(a[i]==i+1)
			setfillstyle(1,2);
		else if(a[i]==0)
			setfillstyle(1,0);
		else
			setfillstyle(1,1);

		rectangle(80+i*80,100,160+i*80,180);
		floodfill(81+i*80,101,15);
		if(a[i]!=0)
		outtextxy(115+i*80,130,itoa(a[i],buffer,10));

		//row 2
		if(a[i+4]==i+5)
			setfillstyle(1,2);
		else if(a[i+4]==0)
			setfillstyle(1,0);
		else
			setfillstyle(1,1);

		rectangle(80+i*80,180,160+i*80,260);
		floodfill(81+i*80,181,15);
		if(a[i+4]!=0)
		outtextxy(115+i*80,210,itoa(a[i+4],buffer,10));

		//row 3
		if(a[i+8]==i+9)
			setfillstyle(1,2);
		else if(a[i+8]==0)
			setfillstyle(1,0);
		else
			setfillstyle(1,1);

		rectangle(80+i*80,260,160+i*80,340);
		floodfill(81+i*80,261,15);
		if(a[i+8]!=0)
		outtextxy(115+i*80,290,itoa(a[i+8],buffer,10));

		//row 4
		if(a[i+12]==i+13)
			setfillstyle(1,2);
		else if(a[i+12]==0)
			setfillstyle(1,0);
		else
			setfillstyle(1,1);

		rectangle(80+i*80,340,160+i*80,420);
		floodfill(81+i*80,341,15);
		if(a[i+12]!=0)
		outtextxy(115+i*80,370,itoa(a[i+12],buffer,10));
	}
}

int wincheck(){
	int flag=0;
	for(int i=0;i<15;i++){
		if(a[i]!=i+1 && a[i]!=0)
			flag=1;
	}
	return flag;
}

int move(){
       int c=getch(),t;
       if(c==119 && (pos-4)>=0){
		t = a[pos];
		a[pos] = a[pos-4];
		a[pos-4] = t;
		pos = pos-4;
		genpuzzle();
       }
       else if(c==97 && (pos-1)>=0 && (pos-1)!=3 && (pos-1)!=7 && (pos-1)!=11){
		t = a[pos];
		a[pos] = a[pos-1];
		a[pos-1] = t;
		pos=pos-1;
		genpuzzle();
       }
       else if(c==115 && (pos+4)<=15){
		t = a[pos];
		a[pos] = a[pos+4];
		a[pos+4] = t;
		pos = pos+4;
		genpuzzle();
       }
       else if(c==100 && (pos+1)<=15 && (pos+1) != 4 && (pos+1) !=8 && (pos+1)!= 12){
		t = a[pos];
		a[pos] = a[pos+1];
		a[pos+1] = t;
		pos=pos+1;
		genpuzzle();
       }
       else if(c==27){
		return 0;
       }
       else if(c==114){
		//while(checkSolvable(a)!=1)
			shuffle(a);
		genpuzzle();
		return 1;
       }
       return 1;
}

void main(){
	int gd=DETECT,gm,t,flag=1;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	//while(checkSolvable(a)!=1)
		shuffle(a);
	genpuzzle();
	while(flag!=0){
		if(kbhit()){
			flag=move()*wincheck();
		}
	}
	getch();
}