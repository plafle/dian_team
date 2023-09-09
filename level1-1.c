#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int a,b,c;
int main() {
	scanf("%d%d%d",&a,&b,&c);
	printf("%d 0 0\n",c);
	printf("%d %d %d\n",a,abs(c-a),1);
	printf("%d %d %d\n",b,abs(c - a) + abs(a - b),0);
	return 0;
}
