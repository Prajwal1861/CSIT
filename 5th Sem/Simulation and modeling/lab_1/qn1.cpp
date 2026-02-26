/* A call center operates 6 days a week, 9 hours a day. It receives 1620 calls per
week. Calculate the mean inter-arrival time and mean arrival rate (calls per
minute).*/

#include<iostream>
using namespace std;

class sim{
    public:
        int total_minutes;
        int total_call;
    
    sim(int tm,int cl){
        total_minutes=tm;
        total_call=cl;
    }
    void calculate(){
        float meanarrivalrate=(float)total_call/total_minutes;
        float interarrival=1/meanarrivalrate;
        cout<<"Mean arrival rate is "<<meanarrivalrate<<" calls/minute"<<endl;
        cout<<"Mean interarrival time is "<<interarrival<<" minutes per call"<<endl;
    }
};
int main(){
    int total_hrs,total_cll;
    int total_days;
    cout<<"Enter the total hours:"<<endl;
    cin>>total_hrs;
    cout<<"Enter the total days:"<<endl;
    cin>>total_days;
    int total_minutes=total_days*total_hrs*60;
    cout<<"Enter the total no of calls:"<<endl;
    cin>>total_cll;
    
    sim s1(total_minutes,total_cll);
    s1.calculate();
}
