import java.io.*;
class exp11
{
public static int z=1;
public static void main(String xt[])
{
 try
 {
 System.out.println("file name is  "+xt[0]);
 }

catch(IndexOutOfBoundsException ox)
{
 System.out.println("Argument missing");
 z=z+2;
 }
if(z==1)
{
 File f1=new File(xt[0]);
 int o,t,th,f,fi,s,se,e,n,j;
 o=t=th=f=fi=s=se=e=n=j=0;
 if(f1.exists())
  {
   if(f1.isFile())
   {
     long l=f1.length();
     System.out.println("length="+l);
     String lis[]=f1.list();
     System.out.println("length="+lis[1]);
     for(int i=0;i<l;i++)
     {
    if(lis[i].equals("0"))
    j++;
    if(lis[i].equals("1"))
    o++;
   if(lis[i].equals("2"))
    t++;
   if(lis[i].equals("3"))
   th++;
   if(lis[i].equals("4"))
   f++;
   if(lis[i].equals("5"))
   fi++;
   if(lis[i].equals("6"))
    s++;
    if(lis[i].equals("7"))
    se++;
   if(lis[i].equals("8"))
   e++;
   if(lis[i].equals("9"))
   n++;
  }
  System.out.println("zero="+j);
  System.out.println("one="+o);
  System.out.println("two="+t);
  System.out.println("three="+th);
  System.out.println("four="+f);
  System.out.println("five="+fi);
  System.out.println("six="+s);
  System.out.println("seven="+se);
  System.out.println("eight="+e);
  System.out.println("nine="+n);
  }
 else
 {
  System.out.println("it is a directory");
  }
}
else
 {
  System.out.println("file does not exist");
  }
}
}
}







