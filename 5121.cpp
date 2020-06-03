#include <iostream>
#include <vector>

const int maxn = 5000;
int a[maxn];

void swap(int &a, int &b) 
{
    a ^= b;
    b ^= a;
    a ^= b;
}

int main(int argc, char *argv[]) 
{
    int n;
    std::cin >> n;
    if (n <= 0 || n > maxn) 
    {
        std::cout << "Invalid input array length:\n"
            "   must be in the range of 1 to "
            << maxn << std::endl;
    }

    for (int i = 0; i < n; ++i) 
    {
        std::cin >> a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        } 
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << a[i] << (i < n - 1 ? ' ' : '\n');
    }
    return 0;
}