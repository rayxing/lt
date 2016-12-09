#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int saifa[80005]; 

void add(int a,int b)
{ 
	cout << a << " " << b << endl; // for debug
	for(int i=0;i<=80000;i++)
	{
		if(i+a > 80000)
		{
			break;
		}

		if(saifa[i]+b > saifa[i+a]) // 累计同时购买多种债卷时的利息
		{
			saifa[i+a] = saifa[i] + b;
		}

		if(i<200) // for debug
		cout << i << "-" << saifa[i] << " ";
	}

	cout << endl; // for debug
}

int main(void)
{
	int n,d,money,year,pay,bond;
	int ii,i;

	scanf("%d",&n);
	for(ii=0;ii<n;ii++)
	{
		memset(saifa,0,sizeof(saifa));
		scanf("%d%d",&money,&year);
		scanf("%d",&d);

		for(i=0;i<d;i++)
		{
			scanf("%d%d",&pay,&bond);
			add(pay/1000,bond);
		}

		// 计算指定年限内最优组合的本金利息总额
		for(i=0;i<year;i++)
		{ 
			cout << saifa[money/1000] << " "; // for debug
			money += saifa[money/1000];
        }
        
		cout << endl; // for debug

        printf("%d/n",money);
    }

    return 0;
}
