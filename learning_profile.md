## 学习档案

### LEVEL 0-1

​	一开始我在如何使用git上遇到了困难

​	教程中并没有指明用什么执行命令行

​	之后我在b站上搜索了相关的视频教程，于是知道了是要在对应文件夹里面gitb bash here，然后再输入那些命令。这样，我成功把我的学习档案的这个文件上传到了github上

​	对于git传输文件的操作方法，具体来说是以下：

>1. $git add<file_name> 对文件进行暂存
>
>2. $git commit -m "message" 对文件进行提交
>
>   ($git status可以对文件进行状态的查询)
>
>3. $git remote add origin url 连接远程仓库（貌似只需要首次添加即可）
>
>4. $git push origin master 创建master分支




### LEVEL 0-2

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
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
```



---



​	至于关于C语言的编译过程，我在网上搜索了相关教程，并配置了GCC环境

​	首先我通过`gcc -E test.c -o test.i`进行预处理，生成了test.i源文件，我理解这部分主要是把一些头文件给调入进来

​	然后我通过`gcc -S test.i -o test.s`将源文件转换为汇编语言

​	然后我通过`gcc -c test.s -o test.o`得到了目标文件

​	最后我通过`gcc test.o -o test`通过链接得到了可执行文件



### LEVEL 1-1

​	就是用一些基础的语法吧



### LEVEL 1-2

​	关于输出格式的说明：和level1-1的官方版本一样，输出了所有重要时刻，每行三个数字，分别表示电梯停靠楼层，电梯已经运行的时间，电梯内的人数。

​	对于文本输入输出，输入文件名是`level1_2.in` ，输出文件名是`level1_2.out`



### LEVEL 1-3

​	首先是关于输入格式的说明：首先会有一个数字来表示有几个人坐电梯，然后接下来有若干行，每行两个数字分别表示对应的人坐的电梯的起点和终点。输入文件名为：`level1_3.in`

​	关于输出格式的说明：回合level1-1的一样。输出文件名为：`level1_3.out`

​	接下来是我的思路：我把电梯的载荷极限设为10人。由于每个人都是一开始就在等待，所以我认为合理的评估指标是电梯运行总时长，所以我的目标是最小化电梯运行总时长。

​	

​	