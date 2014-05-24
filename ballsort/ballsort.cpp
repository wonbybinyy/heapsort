#include<iostream>
#include<algorithm>
#include<ctime>
#include<windows.h>
using namespace std;

const int nmax = 20;
const int nn = 3;
int aa[nmax];

void print(int *a, int n){
	for (int i = 0; i < nmax; ++i){
		cout << a[i] << " ";
	}
	cout << endl;
}

void myswap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void ballsort(int *aa, int n){
	int p1 = 0, p2 = 0, p3 = n - 1, i = 0,j=n-1;
	for (; i < n; ++i)
		if (aa[i] != 1) break;
	p1 = i;
	for (; j>=0; --j)
		if (aa[j] != 3) break;
	p3 = j;
	p2 = p1;
	while (p2 <= p3){
		//print(aa, n);
		if (aa[p2] == 2) { ++p2; continue; }
		else if (aa[p2] == 1){
			myswap(&aa[p1], &aa[p2]);
			++p1;
			++p2;
		}		
		else{
			myswap(&aa[p3], &aa[p2]);
			--p3;
			//++p2;
		}
	}
}

int main(){
	int cycle = 100;
	while (cycle--){
		srand(time(NULL));
		for (int i = 0; i < nmax; ++i){
			aa[i] = (rand() % nn) + 1;
		}
		//int aa[20] = { 1, 1, 3, 2, 1, 3, 3, 1, 2, 1, 3, 3, 3, 1, 2, 1, 2, 3, 2, 2 };
		print(aa, nmax);
		//sort(aa, aa + nmax);
		ballsort(aa, nmax);
		print(aa, nmax);
		cout << endl;
		Sleep(1000);
	}	
	return 0;
}