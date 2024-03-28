// To implement file allocation methods.
#include<stdio.h>
#include<stdlib.h>
main()
{
int f[50], index[50],i, n, st, len, j, c, k, ind,count=0;
for(i=0;i<50;i++)
f[i]=0;
x:printf("Enter the Index Block: ");
scanf("%d",&ind);
if(f[ind]!=1)
{
printf("Enter the Number of Blocks Needed and \nNumber of Files for the Index %d on the Disk : \n", ind);
scanf("%d",&n);
}
else
{
printf("%d Index is Already Allocated. \n",ind);
goto x;
}
y: count=0;
for(i=0;i<n;i++)
{
scanf("%d", &index[i]);
if(f[index[i]]==0)
count++;
}
if(count==n)
{
for(j=0;j<n;j++)
f[index[j]]=1;
printf("Allocated.\n");
printf("File Indexed:\n");
for(k=0;k<n;k++)
printf("%d-------->%d : %d\n",ind,index[k],f[index[k]]);
}
else
{
printf("File in the Index is Already Allocated. \n");
printf("Enter Another File Indexed: ");
goto y;
}
printf("Do You Want to Enter More File(Press Yes For 1 & No For 0): ");
scanf("%d", &c);
if(c==1)
goto x;
else
exit(0);
}