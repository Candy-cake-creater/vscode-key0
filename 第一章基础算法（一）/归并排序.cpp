/*基本思想---分治
-----left--right-----
1.确定分界点:mid=(l+r)/2    是下标
2.递归排序left,right
3.(难点)归并---合二为一
时间复杂度O(nlog2n)
*/

#include<iostream>

using namespace std;

const int N=1000010;

int n;
int q[N],tmp[N];

void merge_sort(int q[],int l,int r)
{
	if(l>=r) return;
	
	int mid=l+r>>1;//取区间中点

	merge_sort(q,l,mid),merge_sort(q,mid+1,r);

	int k=0,i=l,j=mid+1;
	while(i<=mid&&j<=r)
	{
		if(q[i]<=q[j]) tmp[k++]=q[i++];
		else tmp[k++]=q[j++];
	}
	//左右两边有一边没有循环完
	while(i<=mid) tmp[k++]=q[i++];
	while(j<=r) tmp[k++]=q[j++];
	//存回q[]里
	for(i=l;j=0;i<=r;i++,j++) q[i]=tmp[j];

}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&q[i]);

	merge_sort(q,0,n-1);

	for(int i=0;i<n;i++) printf("%d",q[i]);

	return 0;
}