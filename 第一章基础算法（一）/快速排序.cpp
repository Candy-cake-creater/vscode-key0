/*基本思想---分治
l------x(分界点)-----------r
1.确定分界点:q[l],q[(l+r)/2],q[r],随机
2.(重点)调整范围:---(<=x)---x-----(>=x)----
3.递归处理左右两段

暴力:定义数组a[],b[]
	 q[l~r]----q[i]<=x,放入a[]----q[i]>=x,放入b[]
	 a[]放入q[],b[]放入q[].     --a[]-(x)-b[]--

*/