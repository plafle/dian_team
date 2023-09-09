### 学习档案

#### LEVEL 0-1

​	一开始我在如何使用git上遇到了困难

​	教程中并没有指明用什么执行命令行

​	之后我在b站上搜索了相关的视频教程，于是知道了是要在对应文件夹里面gitb bash here，然后再输入那些命令。这样，我成功把我的学习档案的这个文件上传到了github上



#### LEVEL 0-2

​	对于C语言的学习，我采用的是网上搜索资料+代码实践的方法来熟悉C语言

​	然后我首先在网上搜了一下C语言常用库有哪些，然后我决定在之后的程序中把标准库一股脑全部添加进去。

​	以下是我实践的C语言代码，用来熟悉C语言的位运算，数组，函数，文件输入输出等一系列基本操作：

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int a[100005],n;

void silly_reverse(int l,int r) {
	if (r == l)
		return;
	int i;
	for (i=l; i<=l + (r - l) / 2; i++) {
		int t = a[i];
		a[i] = a[r - i + l];
		a[r - i + l] = t;
	}
	int mid = (l + r) >> 1;

	silly_reverse(l,mid);
	silly_reverse(mid + 1,r);
}

int main() {
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%d",&n);
	int i;
	for (i=1; i<=n; i++)
		scanf("%d",&a[i]);
	silly_reverse(1,n);
	for (i=1; i<=n; i++)
		printf("%d ",a[i]);
	printf("\n");
	printf("hello world!");
	return 0;
} 
```



​	