#include <stdio.h>

int main() {
	int n;
	scanf_s("%d", &n);
	int i = 2 * n - 1;
	if (n > 20 || n <= 0) 
		printf("Input is error!");
	else {
		int flag = 0;
		while (n) {
			for (int m = i; m > 0; m--) 
				printf("#");
			printf("\n");
			for (int t=flag+1; t > 0; t--)
				printf(" ");
			flag++;
			i= i - 2;
			n--;
		}
	}
}