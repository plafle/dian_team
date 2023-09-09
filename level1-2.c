#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//有关内容可以去看我的学习档案！ 
int a,b,c;
int main() {
	freopen("level1_2.in","r",stdin);
	freopen("level1_2.out","w",stdout); 
	scanf("elevator %d",&c);
	scanf("%d%d",&a,&b);
	printf("%d 0 0\n",c);
	printf("%d %d %d\n",a,abs(c-a),1);
	printf("%d %d %d\n",b,abs(c - a) + abs(a - b),0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
