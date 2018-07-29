#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    FILE * fp = fopen("out.txt", "w");
    fprintf(fp, "5000\n");
    for(int i=1; i<=5000;i++)
        fprintf(fp,"%d\n",i);
    return 0;
}
