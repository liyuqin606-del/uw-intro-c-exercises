#include <math.h>
#include <stdio.h>
#include <stdlib.h>
static int multbytwo(int n){return n*2;}
static int square(int n){return n*n;}
static void printnchars(int ch,int n){for(int i=0;i<n;i++)putchar(ch);}
static unsigned long long factorial(int n){unsigned long long v=1;for(int i=2;i<=n;i++)v*=i;return v;}
static double celsius(double f){return (f-32.0)*5.0/9.0;}
/* Rejection removes modulo bias for any n in 1..RAND_MAX. */
static int randrange(int n){unsigned long limit=((unsigned long)RAND_MAX+1UL)/ (unsigned)n*(unsigned)n;unsigned long r;do{r=(unsigned long)rand();}while(r>=limit);return (int)(r%(unsigned)n)+1;}
int main(int argc,char **argv){
 if(argc!=2){fprintf(stderr,"usage: week3 1..9\n");return 1;}
 switch(atoi(argv[1])){
 case 1:{int a[]={1,2,3,4,5,6},sum=0;for(size_t i=0;i<sizeof a/sizeof a[0];i++)sum+=a[i];printf("%d\n",sum);break;}
 case 2:for(int i=1;i<=10;i++)printf("%d %d\n",i,multbytwo(i));break;
 case 3:for(int i=1;i<=10;i++)printf("%d %d\n",i,square(i));break;
 case 4:for(int i=1;i<=10;i++){printnchars('*',i);putchar('\n');}break;
 case 5:for(int i=1;i<=10;i++)printf("%d %llu\n",i,factorial(i));break;
 case 6:for(int f=-40;f<=220;f+=10)printf("%d %.2f\n",f,celsius(f));break;
 case 7:case 8:case 9:{int counts[13]={0};double sum=0, sumsq=0;srand(42);for(int i=0;i<1000;i++){int v=randrange(6)+randrange(6);counts[v]++;sum+=v;sumsq+=(double)v*v;}if(atoi(argv[1])==8){for(int i=0;i<10;i++)printf("%d%c",randrange(6),i==9?'\n':' ');}else if(atoi(argv[1])==7)printf("mean: %.3f\nsample standard deviation: %.3f\n",sum/1000,sqrt((sumsq-sum*sum/1000)/999));else for(int i=2;i<=12;i++){printf("%d: %d ",i,counts[i]);printnchars('*',counts[i]);putchar('\n');}break;}
 default:return 1;}return 0;
}
