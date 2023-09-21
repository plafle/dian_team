#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node {
	int st,en;
}a[1005];


int n,est,cap,maxx,minn,dic,cnt;
int i,b[1005]; //b[i] == 0 indicates that it's the start, b[i] == 1 indicates
			 // that it's the end, b[j] == 2 indicates it's finished 

int s_maxx() {
	int maxx = -1,k,maxid;
	for (k=1; k<=n; k++) {
		if (a[k].en > maxx && b[k] == 1) {
			maxx = a[k].en;
			maxid = k;
		}
		if (a[k].st > maxx && b[k] == 0) {
			maxx = a[k].st;
			maxid = k;
		}
	}
	return maxid;
}

int s_minn() {
	int minn = 100,k,minid;
	for (k=1; k<=n; k++) {
		if (a[k].en < maxx && b[k] == 1) {
			minn = a[k].en;
			minid = k;
		}
		if (a[k].st < maxx && b[k] == 0) {
			minn = a[k].st;
			minid = k;
		}
	}
	return minid;
}

int gt(int x) {
	if (b[x] == 0)
		return a[x].st; else
		return a[x].en;	
}

int fd(int x,int dic,int cap) {
	int k;
	for (k=1; k<=n; k++)
		if (a[k].en == x && b[k] == 1)
			return k;
	for (k=1; k<=n; k++)
		if (cap < 4 && a[k].st == x && b[k] == 0)
			return k;
	return -1;
}

int main() {
	printf("please input the number of the passenger\n");
	scanf("%d",&n);
	printf("please input the start floor and the ending floor for every passenger\n");
	for (i=1; i<=n; i++)
		scanf("%d%d",&a[i].st,&a[i].en);
	printf("please input the position of the lift\n");
	scanf("%d",&est);
	puts("");
	printf("the route of the lift is written as follow:\n");
	dic = 1; cnt = (n << 1);
	printf("%d %d %d\n",est,0,0);
	
	
	maxx = s_maxx();
	minn = s_minn(); 
	
	if (est > gt(maxx))
		dic = -dic;
	
	int tcnt = 0;
	for (; cnt; est += dic) {
		tcnt ++;
		int resl = fd(est,dic,cap);
		while (resl != -1) {
			if (b[resl] == 1) {
				b[resl] = 2;
				cnt--; cap--;
				printf("%d %d %d\n",est,tcnt,cap);
			}
			if (b[resl] == 0) {
				if (cap == 4)
					continue;
				cap++; cnt--;
				b[resl] = 1;
				printf("%d %d %d\n",est,tcnt,cap); 
			}
			resl = fd(est,dic,cap);
		}
		maxx = s_maxx();
		minn = s_minn(); 
		if (dic == 1 && est >= gt(maxx) || dic == -1 && est <= gt(minn)) {
			est+=dic;
			tcnt--;
			dic = -dic;
			continue;
		}
	}
	
	return 0;
}
