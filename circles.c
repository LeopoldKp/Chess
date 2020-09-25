#include <stdio.h>
 #include<stdlib.h>
 #include<math.h>
int main()
{
    float r1, r2, x1,x2,y1,y2,c;
    printf("enter two radiuses - the first/the second\n");
    scanf("%f%f",&r1,&r2);
    printf("enter coordinates of their centers - the first(x1,y1)/the second(x2,y2)\n");
    scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
    c=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    c=c-r1-r2;
    if (c==0) {printf("circles are crossing in one point");}
    if ((r1==r2)&&(x1==x2)&&(y1==y2)) {printf("this circles are identical");}
    if (c>0) {printf("circles are not crossing");}
    if ((c<0)&&!((x1==x2)&&(y1==y2))){printf("circles are crossing in two points");}
    if ((x1==x2)&&(y1==y2)&&!(r1==r2)) {printf("circles have indentical center\n");}
    system("pause");
    return 0;
 }