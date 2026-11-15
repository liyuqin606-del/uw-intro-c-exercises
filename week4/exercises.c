#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAP 256
/* Returns EOF only if no bytes were read; discards the remainder of long lines. */
static int read_line(char line[],int cap){int c,n=0,any=0;while((c=getchar())!=EOF&&c!='\n'){any=1;if(n<cap-1)line[n++]=(char)c;}if(c==EOF&&!any)return EOF;line[n]='\0';return n;}
static void reverse(char *s,int n){for(int i=0;i<n/2;i++){char c=s[i];s[i]=s[n-i-1];s[n-i-1]=c;}}
int main(int argc,char **argv){
 if(argc!=2){fprintf(stderr,"usage: week4 1..9\n");return 1;}int c;char s[CAP];
 switch(atoi(argv[1])){
 case 1:while((c=getchar())!=EOF)putchar(c);break;
 case 2:while(read_line(s,CAP)!=EOF)printf("You typed: %s\n",s);break;
 case 3:while(read_line(s,CAP)!=EOF)printf("%s\n",s);break;
 case 4:while((c=getchar())!=EOF)printf("you typed '%c'\n",c);break;
 case 5:{double sum=0,sq=0;int n=0;while(read_line(s,CAP)!=EOF){double x=atoi(s);sum+=x;sq+=x*x;n++;}if(!n){fprintf(stderr,"no numbers\n");return 1;}printf("average: %.2f\n",sum/n);if(n>1)printf("sample standard deviation: %.2f\n",sqrt((sq-sum*sum/n)/(n-1)));break;}
 case 6:{double balance=0;char op[CAP];while(read_line(op,CAP)!=EOF){if(read_line(s,CAP)==EOF){fprintf(stderr,"missing amount\n");return 1;}double amount=atof(s);if(strcmp(op,"deposit")==0)balance+=amount;else if(strcmp(op,"check")==0)balance-=amount;else{fprintf(stderr,"unknown operation\n");return 1;}printf("balance: %.2f\n",balance);}break;}
 case 7:{int x,y;if(scanf("%d%d",&x,&y)!=2)return 1;char direction[16]="";if(y>0)strcpy(direction,"north");else if(y<0)strcpy(direction,"south");if(x>0)strcat(direction,"east");else if(x<0)strcat(direction,"west");puts(*direction?direction:"stationary");break;}
 case 8:while((c=getchar())!=EOF)printf("%c %d\n",c,c);break;
 case 9:{int n;while((n=read_line(s,CAP))!=EOF){reverse(s,n);puts(s);}break;}
 default:return 1;}return 0;
}
