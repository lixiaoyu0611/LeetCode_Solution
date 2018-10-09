#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int a[30];
int n;

int tryplace(int x, int y){
    int j = 1;
    while (j < x){
        if ((a[j] == y) || (abs(x-j) == abs(a[j]-y)))
            return 0;
        j++;
    }
    return 1;
};

void print(){
    for(int i = 1; i <= n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void printGraph()			//图形化打印布局
{
	system("color F0");  	//DOs命令改变背景色和前景色，颜色为16进制数0~F
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			if(a[i] == j)
				cout<<"O";
			else
				cout<<"▅";
		cout<<endl;
	}
	cout<<endl;
}


void place(int x){
    int y;
	if(x > n)
	{
		print();
		printGraph();
	}
	else
	{
		for(y = 1; y <= n; y++)
			if (tryplace(x,y))
			{
				a[x] = y;
				place(x+1);
			}
	}
}

int main(){
    cin>>n;
    place(1);
    return 0;
}
