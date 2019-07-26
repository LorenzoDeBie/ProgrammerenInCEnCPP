#include <stdio.h>
int main(){
	int t[6] = {0,10,20,30,40,50};
	int* pt[3];
	int i;
	int ** ppt;
	for(i=0; i<3; i++){
		pt[i] = &t[2*i];
	}	
	pt[1]++;
	pt[2] = pt[1];
	*pt[1] += 1;
	*pt[2] *= 2;
	ppt = &pt[0];
	(*ppt)++;
	**ppt += 1;
	for(i=0; i<6; i++){
		printf("%d ",t[i]);
	}
	printf("\n");
	for(i=0; i<3; i++){
		printf("%d ",*pt[i]);
	}
	printf("\n");
	return 0;
}
