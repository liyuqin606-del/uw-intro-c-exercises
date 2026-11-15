#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
    if (argc != 2) { fprintf(stderr, "usage: week2 1..7\n"); return 1; }
    switch (atoi(argv[1])) {
    case 1: { int count = 0; for (int i=1;i<=10;i++) if (i>3) count++; printf("%d\n",count); break; }
    case 2: { double sum = 0; for (int i=1;i<=10;i++) sum += i*i; printf("%.1f\n",sum/10); break; }
    case 3: for (int i=1;i<=10;i++) printf("%d is %s\n",i,i%2?"odd":"even"); break;
    case 4: { int x,y; if(scanf("%d%d",&x,&y)!=2) return 1;
      if (!x && !y) puts("stationary");
      else { if(y>0) printf("North"); else if(y<0) printf("South"); if(x>0) printf("East"); else if(x<0) printf("West"); putchar('\n'); } break; }
    case 5: { unsigned long long f=1; for(int i=1;i<=7;i++){f*=i;printf("%d %llu\n",i,f);} break; }
    case 6: { int a=1,b=1; for(int i=0;i<10;i++){printf("%d%c",a,i==9?'\n':' ');int c=a+b;a=b;b=c;} break; }
    case 7: puts("2"); for(int i=3;i<=100;i+=2){int prime=1, limit=(int)sqrt((double)i);for(int d=3;d<=limit;d+=2)if(i%d==0){prime=0;break;}if(prime)printf("%d\n",i);} break;
    default:return 1;
    } return 0;
}
