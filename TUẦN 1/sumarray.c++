#include <iostream>
using namespace std ;
#define MAX 1000000
int main()
{
    int n;
    int sum =0 ;
    cin >> n ;
    int arr[MAX];
    for ( int i =0 ; i < n ; i++ )
    {
        cin >> arr[i] ;
    }
    for(int i = 0; i<n ; i++)
    {
        sum+= arr[i];
    }
    cout << sum ;
    return 0 ;
}