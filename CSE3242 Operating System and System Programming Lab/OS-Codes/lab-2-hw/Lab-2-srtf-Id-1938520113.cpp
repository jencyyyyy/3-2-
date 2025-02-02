#include<iostream>
/*
5
1 0 7
2 2 4
3 4 1
4 5 4
5 3 5
*/
using namespace std;
int main()
{
    int p[10],a[10],b[10],x[10];
    int waiting[10],turnaround[10],completion[10];
    int i,j,smallest,count=0,time,n;
    double avg=0,tt=0,act=0,end;

    cout<<"\nEnter the number of Processes: ";  
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"\nEnter process ID, arrival time & burst time of process: ";  
        cin>>p[i]>>a[i]>>b[i];
    }

    for(i=0; i<n; i++)
        x[i]=b[i];

    b[9]=9999;
    for(time=0; count!=n; time++)
    {
        smallest=9;
        for(i=0; i<n; i++)
        {
            if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )
                smallest=i;
        }
        b[smallest]--;

        if(b[smallest]==0)
        {
            count++;
            end=time+1;
            completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }
    cout<<"Process \tburst-time\tarrival-time\twaiting-time\tturnaround-time\tcompletion-time"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"p"<<p[i]<<"\t\t"<<x[i]<<"\t\t"<<a[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i]<<"\t\t"<<completion[i]<<endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
        act+=completion[i];

    }
    cout<<"\n\nAverage waiting time ="<<avg/n<<endl;
    cout<<"Average Turnaround time ="<<tt/n<<endl;
    cout<<"Average completion time ="<<act/n<<endl;
}