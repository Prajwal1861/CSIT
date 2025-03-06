/*1. Write a program that takes two or more sets as input and produces set operations like union, intersection, difference and symmetric difference as
its output.*/

include<stdio.h>
void readset( char set[],int n){
	for(int i=0;i<n;i++){
		printf("enter the element at index %d\n",i+1);
		scanf(" %c", &set[i]);
			}
}
void printset(char set[],int n){
	printf("{");
	for(int i=0;i<n;i++){
		printf("%c", set[i]);
		if(i<n-1){
			printf(",");
		}
	}
	printf("}\n");
}
void unionset(char seta[],char setb[],int no1,int no2){
	char unionset[no1+no2];
	int k=0;
	for (int i = 0; i < no1; i++) {
        unionset[k++] = seta[i];
    }
     for (int i = 0; i < no2; i++) {
        int present = 0;
        for (int j = 0; j < no1; j++) {
            if (setb[i] == seta[j]) {
                present = 1;
                break;
            }
        }
        if (!present) {
            unionset[k++] = setb[i];
        }
}
printf("{");
for (int i = 0; i < k; i++) {
        printf(" %c", unionset[i]);
        if (i < k - 1) {
            printf(", ");
        }
    }
    printf("}\n");
    
}
void difference(char seta[],char setb[],int no1,int no2){
	for(int i=0;i<no1;i++){
	int unique=1;
	
		for( int j=0;j<no2;j++){
		
			if(seta[i]==setb[j]){
				unique=0;
			    break;
			}  
		}
		if(unique){
				printf(" %c " ,seta[i]);
			
			}
	}
    }
void intersection(char seta[],char setb[], int no1, int no2){
	for(int i=0;i<no1;i++){
		for(int j=0;j<no2;j++){
			if(seta[i]==setb[j]){
				printf("%c" ,seta[i]);
			}
		}
	}
}
int main(){
	int n1,n2;
	printf("enter the number of elements in set1:\n");
	scanf("%d", &n1);
	printf("enter the number of elements in set2:\n");
	scanf("%d", &n2);
	char set1[n1],set2[n2];
	readset(set1,n1);
	readset(set2,n2);
	printf("first set:");
	printset(set1,n1);
	printf("second set:");
	printset(set2,n2);
	printf("intersection:");
	intersection(set1,set2,n1,n2);
	printf("\nunion:");
	unionset(set1,set2,n1,n2);
	printf("A-B:");
	difference(set1,set2,n1,n2);
	printf("\nB-A:");
	difference(set2,set1,n2,n1);
	printf("\nsymmetric difference:");
	difference(set1,set2,n1,n2);
	difference(set2,set1,n2,n1);
	return 0;
}
