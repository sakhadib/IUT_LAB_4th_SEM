//Adib Sakhawat - sakhadib
//IUT, 2024
typedef long long ll;
ll inf = 1e9;
ll neg_inf = -1e9;

#include <bits/stdc++.h>
using namespace std;

bool is_sorted(int *arrstart, int *arrend)
{
    for (int *i = arrstart; i < arrend - 1; i++)
    {
        if (*i > *(i + 1))
        {
            return false;
        }
    }
    return true;
}

int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());

    int n ; 
	cin>>n ; 
	int arr[n+1] ;
	int c=1 ;
	for(int i=1 ; i<=n ; i++)
	{
		cin>>arr[i] ;
	}
	int i=1;
    while(arr[i]<arr[i+1] && i<n)
    {
    	i++;
	}
    int l= i;
	 while(arr[i]>arr[i+1] && i<n)
    {
    	i++;
	}
    int r=i+1;
    reverse(arr+l, arr+r);
    if(is_sorted(arr+1,arr+n+1))
    {
        cout<<"yes\n";
        cout<<l<<" "<<r-1;
    }
    else cout<<"no";
    
    return 0;
}