#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
int a[10],b[10],c[10];
void push(char inRod,int value){
	if(inRod=='A'){
		for(int i=0;i<10;i++){
			if(a[i]==0){
				a[i]=value;
				break;
			}
		}
	}else if(inRod=='B'){
		for(int i=0;i<10;i++){
			if(b[i]==0){
				b[i]=value;
				break;
			}
		}
	}else{
		for(int i=0;i<10;i++){
			if(c[i]==0){
				c[i]=value;
				break;
			}
		}
	}
}
int pop(char from){
	int temp=0;
	if(from=='A'){
		for(int i=0;i<10;i++){
			if(a[i]==0){
				temp=a[i-1];
				a[i-1]=0;
				break;
			}
		}
	}else if(from=='B'){
		for(int i=0;i<10;i++){
			if(b[i]==0){
				temp=b[i-1];
				b[i-1]=0;
				break;
			}
		}
	}else{
		for(int i=0;i<10;i++){
			if(c[i]==0){
				temp=c[i-1];
				c[i-1]=0;
				break;
			}
		}
	}
	return temp;
}
void drawa(){
	cleardevice();
	//base
	for(int j=0; j<=300 ; j=j+150){
		line(100+j,getmaxy()-100,200+j,getmaxy()-100);
		line(150+j,getmaxy()-100,150+j,getmaxy()-300);
	}

	for(int i=0;i<10;i++){
		if(a[i]==0){
			break;
		}
		rectangle(100+i*10,getmaxy()-100-i*20,200-i*10,getmaxy()-120-i*20);
		//setfillstyle(SOLID_FILL,a[i]);
		//floodfill(100+i*10+1,getmaxy()-100-i*20+1,15);
	}
	for(i=0;i<10;i++){
		if(b[i]==0){
			break;
		}
		rectangle(250+i*10,getmaxy()-100-i*20,350-i*10,getmaxy()-120-i*20);
	}

	for(i=0;i<10;i++){
		if(c[i]==0){
			break;
		}
		rectangle(400+i*10,getmaxy()-100-i*20,500-i*10,getmaxy()-120-i*20);
	}
	delay(1000);
}
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
	printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
	push(to_rod,pop(from_rod));
	drawa();
	return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    push(to_rod,pop(from_rod));
    drawa();
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

void main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    int n = 4;
    for(int i=n,j=0;i>0;i--,j++){
		a[j]=i;
	}
    towerOfHanoi(n, 'A', 'C', 'B');
    getch();
    //closegraph();

}
