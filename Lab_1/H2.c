#include<stdio.h>

int main()
{ 
  int i,j,t=0,T,n,max;
  //printf("����ʵ��������ţ�");
  scanf("%d",&T);
  //printf("ʵ������:%d\n",m);
  for(j=0;j<T;j++) 
  {
  scanf("%d",&n);
  //printf("��������:%d\n",n);
  int a[n],b[n-1];
  //printf("Ϊ����Ԫ�ظ�ֵ��\n");
  
  for(i=0;i<n;i++)
  {
  	scanf("%d",&a[i]);
  }
  for(i=0;i<=n-2;i++)
  {
  	b[i]=a[i]-a[i+1];
  }
   int f = b[0],G= b[0];
    for (i = 1; i < n-1; i++)
    {
        if (f >0)
            f = f+b[i];
        else
            f = b[i];
        if (G < f)
            G = f;
    }
  max=G;
  printf("%d\n",max);
}
  return 0;
}

