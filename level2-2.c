#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node {
	int st,en,tm,lb;
} a[1005],t;


int n,est1,est2,cap1,cap2,maxx1,minn1,maxx2,minn2,dic1,dic2,cnt1,cnt2,cur1,cur2;
int i,b[1005]; //b[i] == 0 indicates that it's the start, b[i] == 1 indicates
// that it's the end, b[j] == 2 indicates it's finished

int s_maxx(int id) {
	int maxx = -1,k,maxid;
	for (k=1; k<=n; k++) {
		if (a[k].en > maxx && b[k] == 1 && (a[k].lb == id || a[k].lb == 3)) {
			maxx = a[k].en;
			maxid = k;
		}
		if (a[k].st > maxx && b[k] == 0 && (a[k].lb == id || a[k].lb == 3)) {
			maxx = a[k].st;
			maxid = k;
		}
	}
	return maxid;
}

int s_minn(int id) {
	int minn = 100,k,minid;
	for (k=1; k<=n; k++) {
		if (a[k].en < minn && b[k] == 1 && (a[k].lb == id || a[k].lb == 3)) {
			minn = a[k].en;
			minid = k;
		}
		if (a[k].st < minn && b[k] == 0 && (a[k].lb == id || a[k].lb == 3)) {
			minn = a[k].st;
			minid = k;
		}
	}
	return minid;
}

int gt(int x) {
	if (b[x] == 0)
		return a[x].st;
	else
		return a[x].en;
}

int fd(int x,int dic,int cap,int tcnt,int id) {
	int k;
	for (k=1; k<=n; k++)
		if (a[k].en == x && b[k] == 1 && (a[k].lb == id || a[k].lb == 3))
			return k;
	for (k=1; k<=n; k++)
		if (cap < 4 && a[k].st == x && b[k] == 0 && cap * (a[k].tm - tcnt) <= 10 && (a[k].lb == id || a[k].lb == 3) && dic * (a[k].en - a[k].st) > 0)
			return k;
	return -1;
}

int abs(int x) {
	if (x >= 0) return x;
	else return -x;
}


void sort(int l,int r) {
	int i,j;
	for (i=l; i<=r; i++)
		for (j=l; j<i; j++)
			if (abs(a[i].en - a[i].st) > abs(a[j].en - a[j].st)) {
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
	for (i=1; i<=n / 3; i++)
		a[i].lb = 1;
	for (i=n / 3 + 1; i<=n; i++)
		a[i].lb = 2;// allocate the mission
}

int main() {
	printf("please input the position of the lifts\n");
	scanf("%d%d",&est1,&est2);
	printf("please input the number of the passenger\n");
	scanf("%d",&n);
	printf("please input the start floor, the ending floor and the time for every passenger\n");
	for (i=1; i<=n; i++)
		scanf("%d%d%d",&a[i].st,&a[i].en,&a[i].tm);

	sort(1,n);

	puts("");
	printf("the route of the lift is written as follow:\n");
	dic1 = 1;
	dic2 = 1;
	cnt1 = ((n / 3) << 1);
	cnt2 = n * 2 - cnt1;
	printf("elevator:1 position:%d time:%d loads:%d\n",est1,0,0);
	printf("elevator:2 position:%d time:%d loads:%d\n",est2,0,0);

	maxx1 = s_maxx(1);
	minn1 = s_minn(1);
	maxx2 = s_maxx(2);
	minn2 = s_minn(2);

	if (est1 > gt(maxx1)) dic1 = -dic1;
	if (est2 > gt(maxx2)) dic2 = -dic2;

	int tcnt1 = -1;
	int tcnt2 = -1;
	cur1 = 0;
	cur2 = 0;
	
	for (; (cnt1 + cnt2 > 0); est1 += dic1,est2 += dic2) {
		tcnt1 ++;
		tcnt2 ++;
		int resl = fd(est1,dic1,cap1,tcnt1,1);
		while (resl != -1) {
			if (b[resl] == 1) {
				b[resl] = 2;
				cnt1--;
				cap1--;
				printf("elevator:1 position:%d time:%d loads:%d\n",est1,tcnt1,cap1);
			}
			if (b[resl] == 0) {
				cur1 = resl;
				a[resl].lb = 1;
				cap1++;
				cnt1--;
				b[resl] = 1;
				if (a[resl].tm > tcnt1)
					tcnt1 = a[resl].tm;
				printf("elevator:1 position:%d time:%d loads:%d\n",est1,tcnt1,cap1);
			}
			resl = fd(est1,dic1,cap1,tcnt1,1);
		}

		resl = fd(est2,dic2,cap2,tcnt2,2);
		while (resl != -1) {
			if (b[resl] == 1) {
				b[resl] = 2;
				cnt2--;
				cap2--;
				printf("elevator:2 position:%d time:%d loads:%d\n",est2,tcnt2,cap2);
			}
			if (b[resl] == 0) {
				cur2 = resl;
				a[resl].lb = 2;
				cap2++;
				cnt2--;
				b[resl] = 1;
				if (a[resl].tm > tcnt2)
					tcnt2 = a[resl].tm;
				printf("elevator:2 position:%d time:%d loads:%d\n",est2,tcnt2,cap2);
			}
			resl = fd(est2,dic2,cap2,tcnt2,2);
		}

		if (cnt1 == 0 || cnt2 == 0) {
			int i;
			for (i = 1; i<=n; i++) a[i].lb = 3;
			if (cnt2) a[cur2].lb = 2;
			else a[cur1].lb = 1;
		}

		maxx1 = s_maxx(1);
		minn1 = s_minn(1);
		maxx2 = s_maxx(2);
		minn2 = s_minn(2);

		if (dic1 == 1 && est1 >= gt(maxx1) || dic1 == -1 && est1 <= gt(minn1)) {
			est1+=dic1;
			tcnt1--;
			dic1 = -dic1;
			continue;
		}
		if (dic2 == 1 && est2 >= gt(maxx2) || dic2 == -1 && est2 <= gt(minn2)) {
			est2+=dic2;
			tcnt2--;
			dic2 = -dic2;
			continue;
		}
	}

	return 0;
}
