/*基本思想---分治
l------x(分界点)-----------r
1.确定分界点:q[l],q[(l+r)/2],q[r],随机    是数值
2.(难点)调整范围:---(<=x)---x-----(>=x)----
3.递归处理左右两段
时间复杂度:O(n)
暴力:定义数组a[],b[]
	 q[l~r]----q[i]<=x,放入a[]----q[i]>=x,放入b[]
	 a[]放入q[],b[]放入q[].     --a[]-(x)-b[]--

优美:定义指针i,j
     i在大于x时停下,j在小于x时停下,然后交换.

*/
#include<iostream> 

using namespace std;

const int N=1e6+10;
int n;
int q[N];

void quick_sort(int q[],int l,int r)
{
	if(l>=r) return;//或者l==r

	int x=q[l],i=l-1,j=r+1;
	while(i<j)
	{
		do i++; while(q[i]<x);
	    do j--; while(q[j]>x);
		if(i<j) //swap(q[i],q[j]);
		{
			int t=q[i];
			q[i]=q[j];
			q[j]=t;
		}
	}
	quick_sort(q,l,j);
	quick_sort(q,j+1,r);
}
/*用i写
void quick_sort(int q[], int l, int r)
{
	if (l >= r)
		return; 

	int x = q[(l+r+1)/2], i = l - 1, j = r + 1;
	while (i < j)
	{
		do
			i++;
		while (q[i] < x);
		do
			j--;
		while (q[j] > x);
		if (i < j)  swap(q[i],q[j]);
	}
	quick_sort(q, l, i-1);
	quick_sort(q,i, r);
}
*/
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&q[i]);

	quick_sort(q,0,n-1);

	for(int i=0;i<n;i++) printf("%d",q[i]);

	return 0;
}