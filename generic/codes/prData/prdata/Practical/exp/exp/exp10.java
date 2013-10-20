import java.io.*;
class exp10
{
public static int z=1;
public static void main(String xt[])
{
 try
 {
 System.out.println(" first file name is  "+xt[0]);
 System.out.println(" second file name is  "+xt[1]);
 }

catch(IndexOutOfBoundsException ox)
{
 System.out.println("Argument missing");
 z=z+2;
 }
if(z==1)
{
 File f1=new File(xt[0]);
 File f2=new File(xt[1]);
 if(f1.exists())
 {
 f1.renameTo(f2);
 System.out.println(" renamed successfully");
 }
else
{
System.out.print(" first file is not exist");
}
} 
}
}





