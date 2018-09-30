#include<stdio.h>
#include<stdbool.h>

bool Find(int *matrix,int m,int n,int key)
{
	if(matrix==NULL || m<1 || n<1)
		return false;
	int row = 0;
	int col = n-1;
	while(row<=m-1 && col>=0)
	{
		if(matrix[row*n+col] == key)
			return true;
		else if(matrix[row*n+col] > key)
			col--;
		else
			row++;
	}
	return false;
}

int main()
{
	int m,n;
	while(~scanf("%d %d",&m,&n))
	{
		int key,i;
		static int matrix[1000*1000] = {0};
		scanf("%d",&key);
		for(i=0;i<m*n;i++)
			scanf("%d",matrix+i);
		bool result = Find(matrix,m,n,key);
		if(result)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
//2939
