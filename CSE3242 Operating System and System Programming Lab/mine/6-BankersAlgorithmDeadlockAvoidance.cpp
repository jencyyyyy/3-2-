/*Banker*/
#include <bits/stdc++.h>

using namespace std;
//create the process structure
struct process
{
    string id;
    vector<int> max_need, allocation, need;
};

bool safetyAlgorithm(vector<int> work, vector<process> x)//work currently availabe resource
{
    string sequence = "";
    int no_of_resource = work.size();
    int no_of_process = x.size();
    vector<bool> finish(no_of_process, false);

    while (true)
    {
        bool found = false;
        for (int i = 0; i < no_of_process; i++)
        {
            if (finish[i])
            {
                continue;
            }
            bool ok = true;
            for (int j = 0; j < no_of_resource; j++)
            {
                if (x[i].need[j] > work[j])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                found = true;
                finish[i] = true;
                for (int j = 0; j < no_of_resource; j++)
                {
                    work[j] += x[i].allocation[j];
                }
                sequence += x[i].id + " ";
            }
        }
        if (!found) break;
    }
    for (int i = 0; i < no_of_process; i++)
    {
        if (!finish[i])
        {
            return false;
        }
    }
    cout << sequence << "\n";
    return true;
}

int main()
{
    int no_of_resource; 
    cout<<"Total number of resources: ";
    cin >> no_of_resource;
    vector<int> available(no_of_resource);
    cout<<"Enter available resources: ";
    for (int &value: available)
    {
        cin >> value; 
    }

    int no_of_process; // Total number of processes
    cout<<"Enter Total number of processes: ";
    cin >> no_of_process;
    vector<process> x(no_of_process);
    cout<<"Enter Process ID ::::: Allocation ::::: Max\n";
    cout<<"Enter Process ID: ";

    for (int i = 0; i < no_of_process; i++)
    {
        x[i].max_need.resize(no_of_resource);
        x[i].allocation = x[i].need = x[i].max_need;
        cin >> x[i].id;
        cout<<"Enter allocation for Process"<< i+1 <<": ";
        for (int &value: x[i].allocation)
        {
            
            cin >> value; // Total number of already allocated resources
            
        }
         cout<<"\nEnter Max: ";
        for (int j = 0; j < no_of_resource; j++)
        {
           
            cin >> x[i].max_need[j]; // Maximum number resources a process can request
            x[i].need[j] = x[i].max_need[j] - x[i].allocation[j];
            
        }
        cout<<endl;
    }

    if (safetyAlgorithm(available, x))
    {
        cout << "Safe state"<<endl;
    }
    else cout << "Not safe state!"<<endl;
}

/*
Input:
3
3 3 2
5
T0   0 1 0   7 5 3
T1   2 0 0   3 2 2
T2   3 0 2   9 0 2
T3   2 1 1   2 2 2
T4   0 0 2   4 3 3

Output:
T1 T3 T4 T0 T2 
The system is in a safe state
*/