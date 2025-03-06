/*Write a program that takes name and age of a 5 persons as an input and gives the degree of membership of the person as its output according to
following membership functions.

a. Degree of membership = 1 if age<=20
Degree of membership = (30-age)/10 if age>20 and age<=30
Degree of membership = 0 if age>30

b. Degree of membership = 1 if age<=15
Degree of membership = (35-age)/20 if age>15 and age<=35
Degree of membership = 0 if age>35

Perform set operations according to rules of fuzzy sets, on these
two sets.*/

#include<stdio.h>
struct Person{
	char name[500];
	int age;
};
typedef struct Person Person;
int main(){
	int i;
	Person p[5];
	for(i=0;i<5;i++){
		printf("enter the name of person in index %d \n",i+1);
		scanf("%s" ,p[i].name);
		printf("enter the age of person in index %d\n",i+1);
		scanf("%d" ,&p[i].age);
	}
	printf(" by first membership function:\n");
	float degree=0.0;
	for(i=0;i<5;i++){
		if(p[i].age<=20){
			printf("degree of membership of  %s is 1\n" ,p[i].name);
		}
		else if(p[i].age>20 && p[i].age<=30){
			degree=(30.0-p[i].age)/10.0;
			printf("degree of membership of %s is  %.2f\n", p[i].name,degree);
			
		}
		else
		   printf("degree of membership of %s is 0\n",p[i].name);	
		
	}
	printf(" by second membership function:\n");
	for(i=0;i<5;i++){
		if(p[i].age<=15){
			printf("degree of membership of  %s is 1\n" ,p[i].name);
		}
		else if(p[i].age>15 && p[i].age<=35){
			degree=(35.0-p[i].age)/20.0;
			printf("degree of membership of %s is  %.2f\n", p[i].name,degree);
			
		}
		else
		   printf("degree of membership of %s is 0\n",p[i].name);	
		
	}
	return 0;
}
