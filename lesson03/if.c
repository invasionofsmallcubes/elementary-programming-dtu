int i;
int j = 0;
for(i=0;i<n;i++) {
	if (i % 0 == 0) {
		continue;
	}
	if ( i == n-1) {
		break;
	}
	j=j+i;
}
printf("%d",j)