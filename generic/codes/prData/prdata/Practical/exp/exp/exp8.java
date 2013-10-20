import java.util.*;
class exp8
{
public static void main(String xt[]) 
{
Random r=new Random();

int t,s=0,f;
try
{
  t=Integer.parseInt(xt[0]);
 }
catch(IndexOutOfBoundsException  ox)
{
System.out.println("Not provide command line argument so t=100");
t=100;
}
int a[]=new int[t+2];
System.out.println("value=");
for(int i=0;i<t;i++)
{
a[i]=r.nextInt();
System.out.println(a[i]);
s=s+a[i];
}
f=s/t;
System.out.println("Mean value= "+f);
}
}

