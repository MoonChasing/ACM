#include <bits/stdc++.h>

using namespace std;

int a[3][3];
int main()
{
    for( a[0][0]=-1; a[0][0]<=1; a[0][0]++)
    for( a[0][1]=-1; a[0][1]<=1; a[0][1]++)
    for( a[0][2]=-1; a[0][2]<=1; a[0][2]++)
    for( a[1][0]=-1; a[1][0]<=1; a[1][0]++)
    for( a[1][1]=-1; a[1][1]<=1; a[1][1]++)
    for( a[1][2]=-1; a[1][2]<=1; a[1][2]++)
    for( a[2][0]=-1; a[2][0]<=1; a[2][0]++)
    for( a[2][1]=-1; a[2][1]<=1; a[2][1]++)
    for( a[2][2]=-1; a[2][2]<=1; a[2][2]++)
    {
        set<int> b;
        for(int i=0; i<3; i++)
        {
            int sum = 0;
            int sum1 = 0;
            for(int j=0; j<3; j++)
            {
                sum += a[i][j];
                sum1 += a[j][i];
            }
            b.insert(sum);
            b.insert(sum1);
        }

        if(b.size() == 6)
        {
            puts("--------------------------");
            for(int i=0; i<3; i++)
            {
                for(int j=0; j<3; j++)
                    printf("%d%c", a[i][j], " \n"[j==2]);
            }
            puts("--------------------------");
        }

    }
    return 0;
}

//#include <bits/stdc++.h>
//
//using namespace std;
//
//int a[4][4];
//int main()
//{
//    int    cnt = 0;
//    for( a[0][0]=-1; a[0][0]<=1; a[0][0]++)
//    for( a[0][1]=-1; a[0][1]<=1; a[0][1]++)
//    for( a[0][2]=-1; a[0][2]<=1; a[0][2]++)
//    for( a[0][3]=-1; a[0][3]<=1; a[0][3]++)
//    for( a[1][0]=-1; a[1][0]<=1; a[1][0]++)
//    for( a[1][1]=-1; a[1][1]<=1; a[1][1]++)
//    for( a[1][2]=-1; a[1][2]<=1; a[1][2]++)
//    for( a[1][3]=-1; a[1][3]<=1; a[1][3]++)
//    for( a[2][0]=-1; a[2][0]<=1; a[2][0]++)
//    for( a[2][1]=-1; a[2][1]<=1; a[2][1]++)
//    for( a[2][2]=-1; a[2][2]<=1; a[2][2]++)
//    for( a[2][3]=-1; a[2][3]<=1; a[2][3]++)
//    for( a[3][0]=-1; a[3][0]<=1; a[3][0]++)
//    for( a[3][1]=-1; a[3][1]<=1; a[3][1]++)
//    for( a[3][2]=-1; a[3][2]<=1; a[3][2]++)
//    for( a[3][3]=-1; a[3][3]<=1; a[3][3]++)
//    {
//        set<int> b;
//        for(int i=0; i<4; i++)
//        {
//            int sum = 0;
//            int sum1 = 0;
//            for(int j=0; j<4; j++)
//            {
//                sum += a[i][j];
//                sum1 += a[j][i];
//            }
//            b.insert(sum);
//            b.insert(sum1);
//        }
//
//        if(b.size() == 8)
//        {
//            cnt ++;
//            puts("--------------------------");
//            for(int i=0; i<4; i++)
//            {
//                for(int j=0; j<4; j++)
//                    printf("%d%c", a[i][j], " \n"[j==3]);
//            }
//            puts("--------------------------");
//            if (cnt == 5)
//            exit(0);
//        }
//
//    }
//    return 0;
//}

//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int a[3][3];
//int main()
//{
//    for( a[0][0]=-1; a[0][0]<=1; a[0][0]++)
//    for( a[0][1]=-1; a[0][1]<=1; a[0][1]++)
//    for( a[1][0]=-1; a[1][0]<=1; a[1][0]++)
//    for( a[1][1]=-1; a[1][1]<=1; a[1][1]++)
//    {
//        set<int> b;
//        for(int i=0; i<2; i++)
//        {
//            int sum = 0;
//            int sum1 = 0;
//            for(int j=0; j<2; j++)
//            {
//                sum += a[i][j];
//                sum1 += a[j][i];
//            }
//            b.insert(sum);
//            b.insert(sum1);
//        }
//
//        printf("%d\n", b.size());
//        if(b.size() == 4)
//        {
//            puts("--------------------------");
//            for(int i=0; i<2; i++)
//            {
//                for(int j=0; j<2; j++)
//                    printf("%d%c", a[i][j], " \n"[j==1]);
//            }
//            puts("--------------------------");
//        }
//
//    }
//    return 0;
//}

//#include <bits/stdc++.h>
//
//using namespace std;
//int n;
//int a[100][100];
//bool dfs(int r, int c, int val)
//{
//    for()
//}
//
//int main()
//{
//    return 0;
//}





























