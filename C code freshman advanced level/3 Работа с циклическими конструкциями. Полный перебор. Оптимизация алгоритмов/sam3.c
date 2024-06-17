#include <stdio.h>

int main(void)
{
	int k;
	int q=0,n5,n3,n1,t=29,i=0,u;
	scanf("%d", &k);
	for(n5=0;n5<=(t/5);n5++){for(n3=0;n3<=(t/3);n3++){for(n1=0;n1<=t;n1++){if((t-5*n5-3*n3-n1==0)&&(n1+n3+n5<=9)){i++;}}}}
	printf("%d\n\n",i);
	unsigned long long sum, next_sum, term, n;
	next_sum = 0;
	n = 0;
	
	while (next_sum <= 2147483647)
	{
		sum = next_sum;
		n += 1;
		term = 1;
		for (int i = 1; i <= k; i++) term *= (2*n);
		next_sum += term;
	}

	printf("%llu\n", sum);
	printf("%llu\n", n - 1);
	if (term > 2147483647) printf("*\n");
	else printf("+\n");
}

