#include <stdio.h>

int main(void) {
	int n, cnt = 0;
	int digitOfTen, digitOfOne;
	int cNum;
	scanf("%d", &n);

	cNum = n;
	do{
		digitOfTen = cNum / 10;
		digitOfOne = cNum % 10;

		cNum = ((digitOfOne + digitOfTen) % 10) + (digitOfOne * 10);
		cnt++;
	} while (cNum != n);

	printf("%d", cnt);
}