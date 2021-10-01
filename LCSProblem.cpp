#include<stdio.h>
#include<string.h>
 
int i,j,a,b,c[20][20];
char x[20],y[20],m[20][20];
 
void print(int i,int j)
{
                if(i==0 || j==0)
                                return;
                if(m[i][j]=='c')
                {
                                print(i-1,j-1);
                                printf("%c",x[i-1]);
                }
                else if(m[i][j]=='u')
                                print(i-1,j);
                else
                                print(i,j-1);
}
 
void lcs()
{
                a=strlen(x);
                b=strlen(y);
                for(i=0;i<=a;i++)
                                c[i][0]=0;
                for(i=0;i<=b;i++)
                                c[0][i]=0;
                            for(i=1;i<=a;i++)
                            {
							for(j=1;j<=b;j++)
                                {
                                                if(x[i-1]==y[j-1])
                                                {
                                                                c[i][j]=c[i-1][j-1]+1;
                                                                m[i][j]='c';
                                                }
                                                else if(c[i-1][j]>=c[i][j-1])
                                                {
                                                                c[i][j]=c[i-1][j];
                                                                m[i][j]='u';
                                                }
                                                else
                                                {
                                                                c[i][j]=c[i][j-1];
                                                                m[i][j]='l';
                                                }
                                }
                            }
}
int main()
{
                printf("Enter 1st sequence:");
                scanf("%s",x);
                printf("Enter 2nd sequence:");
                scanf("%s",y);
                printf("\nThe Longest Common Subsequence is ");
                lcs();
                print(a,b);
return 0;
}
