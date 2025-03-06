/*2. Write a program that takes two or more sets as input and produces their Cartesian product as output.*/

#include<stdio.h>
void readset( char set[],int n){
	for(int i=0;i<n;i++){
		printf("enter the element at index %d\n",i+1);
		scanf(" %c", &set[i]);
			}
	printf("{");
	for(int i=0;i<n;i++){
		printf("%c", set[i]);
		if(i<n-1){
			printf(",");
		}
	}
	printf("}\n");		
}
int main(){
	int n1,n2;
	printf("enter the number of elements in set1:");
	scanf("%d",&n1);
	printf("enter the number of elements in set2:");
	scanf("%d",&n2);
	char set1[n1],set2[n2];
	readset(set1,n1);
	readset(set2,n2);
	int i,j;
	printf("cartesian product:{");
	for(j=0;j<n1;j++){
		for(i=0;i<n2;i++){
			printf("(%c,%c)" ,set1[j],set2[i]);	
			if(j<n1-1){
				printf(",");
			}
		}
		
	}
	printf("}\n");
	return 0;
}
