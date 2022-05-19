#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

void genBars(int a[],int n){
	cleardevice();
	for(int i=0;i<n;i++){
		setfillstyle(1,a[i]+1);
		rectangle(200+25*i,200-25*a[i],225+25*i,225);
		floodfill(201+25*i,201-25*a[i],15);
	}
}

void bubbleSortBars(int a[],int n)
{
	genBars(a,n);
	int t;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[i]>a[j]){
				t = a[i];
				a[i] = a[j];
				a[j] = t;
				delay(1000);
				genBars(a,n);
			}
		}
	}
}

void main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	int a[] = {5,4,3,2,1};
	int n=sizeof(a)/sizeof(a[0]);
	bubbleSortBars(a,n);
	getch();
	closegraph();
}