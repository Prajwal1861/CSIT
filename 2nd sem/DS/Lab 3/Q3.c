/*3. Verify the Modus Tollens using the truth table.*/

#include<iostream>
using namespace std;
int main(){
	int p[8]={1,1,1,1,0,0,0,0},
	q[8]={1,1,0,0,1,1,0,0},
	r[8]={1,0,1,0,1,0,1,0},
	m[8],n[8],a[8],b[8];
	for(int i=0;i<8;i++){
		m[i]=(p[i]|q[i]);
	}
	for(int i=0;i<8;i++){
		if((p[i]&q[i])==1&&(r[i]==0)){
			n[i]=0;
		}
		else
		{
			n[i]=1;
		}
	}
	for(int i=0;i<8;i++){
		if(q[i]==1&&(!r[i]==0)){
			a[i]=0;
		}
		else{

			a[i]=1;
		}
	}
	for(int i=0;i<8;i++){
		b[i]=!p[i];
	}
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<"|p  |"<<"\t"<<"q  |"<<"\t"<<"r  |"<<"\t"<<"(pVq)"<<"   |"<<"(p&q)->r"<<"|"<<"(q)->(!r)"<<" |"<<"!p   |"<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
	for(int i=0;i<8;i++){
		cout<<"|"<<p[i]<<"  |"<<"\t"<<q[i]<<"  |"<<"\t"<<r[i]<<"  |"<<"\t"<<" "<<m[i]<<"\t|"<<" "<<n[i]<<"\t"<<" |"<<"\t"<<a[i]<<"   |"<<b[i]<<"\t"<<"  |"<<endl;
	}
		cout<<"-----------------------------------------------------------"<<endl;
	for(int i=0;i<8;i++){
		if(m[i]==1&&n[i]==1&&a[i]==1&&b[i]==1){
			cout<<"if (pVq) is true and (p&q)->r is true also (q)->(!r) is true then !p is also true";
		}
	}	
	return 0;
}
