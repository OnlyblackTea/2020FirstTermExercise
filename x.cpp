#include <iostream>
#include <cstdlib>
using namespace std;
int high,width;  //页面大小 
int position_x,position_y;  //飞机位置 
void startup()  //数据初始化 
{
	high=18;
	width=30;  
	position_x=high/2;
	position_y=width/2;   
}
void show() //显示画面 
{
	system("cls"); 
	int i,j;
	for(i=0;i<high;i++)
	{
		for(j=0;j<width;j++)
		{
			if((i==position_x)&&(j==position_y))   
			cout<<"*";  //输出飞机 
			else cout<<" ";  //输出空格 
		}
	}
}
void updateWithoutInput()  //与用户输入无关的更新 
{
	
}
void updateWithInput()   //与用户输入有关的更新 
{
	
}
int main()
{
	startup();
	while(1)
	{
		show();
		updateWithoutInput();
		updateWithInput();
		_sleep(1000);
	}
} 
