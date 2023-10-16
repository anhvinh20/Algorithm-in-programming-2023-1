#include <iostream>
using namespace std ;
void list(int n)
{
    for( int i = 100; i<=999 ; i++)
    {
        if(i%n==0)
        cout << i << "\t";
    }
}
int main()
{
    list(17);
}