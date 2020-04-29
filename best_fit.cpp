#include<bits/stdc++.h> 
using namespace std; 
void bestFit(int blockSize[], int m, int processSize[], int n) 
{ 
	int allocation[n]; 
	memset(allocation, -1, sizeof(allocation)); 
	for (int i=0; i<n; i++) 
	{ 
		int bestIdx = -1; 
		for (int j=0; j<m; j++) 
		{ 
			if (blockSize[j] >= processSize[i]) 
			{ 
				if (bestIdx == -1) 
					bestIdx = j; 
				else if (blockSize[bestIdx] > blockSize[j]) 
					bestIdx = j; 
			} 
		} 
		if (bestIdx != -1) 
		{ 
			allocation[i] = bestIdx; 
			blockSize[bestIdx] -= processSize[i]; 
		} 
	} 

	cout << "\nProcess No.\tProcess Size\tBlock no.\n"; 
	for (int i = 0; i < n; i++) 
	{ 
		cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t"; 
		if (allocation[i] != -1) 
			cout << allocation[i] + 1; 
		else
			cout << "Not Allowed"; 
		cout << endl; 
	} 
} 
int main() 
{ 
	cout<<"enter the number of blocks available "<<endl;
    int n;
    cin>>n;
    cout<<"enter the number of process"<<endl;
    int p;
    cin>>p;
	int blockSize[n] ;
    cout<<"enter the size of each block"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>blockSize[i];
    } 
    cout<<"enter the size of each process"<<endl;
	int processSize[p] ;
    for(int i=0;i<p;i++)
    {
        cin>>processSize[i];
    } 
	bestFit(blockSize, n, processSize, p); 

	return 0 ; 
} 

