#include <iostream>
#include <cstdlib>
using namespace std;
int high,width;  //ҳ���С 
int position_x,position_y;  //�ɻ�λ�� 
void startup()  //���ݳ�ʼ�� 
{
	high=18;
	width=30;  
	position_x=high/2;
	position_y=width/2;   
}
void show() //��ʾ���� 
{
	system("cls"); 
	int i,j;
	for(i=0;i<high;i++)
	{
		for(j=0;j<width;j++)
		{
			if((i==position_x)&&(j==position_y))   
			cout<<"*";  //����ɻ� 
			else cout<<" ";  //����ո� 
		}
	}
}
void updateWithoutInput()  //���û������޹صĸ��� 
{
	
}
void updateWithInput()   //���û������йصĸ��� 
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
