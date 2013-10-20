import java.util.*;
class exp9
{
public static void main(String xt[])
{
Vector v=new Vector();
int z=0;
try
{
System.out.println("first value= "+ xt[0]);
}
catch(IndexOutOfBoundsException ox)
{
z=z+2;
System.out.print("no argument");
}
if(z==0)
{
for(int i=0;i<xt.length;i++)
 v.addElement(new Double(Double.parseDouble(xt[i])));
int l=v.size();
System.out.println("value in reverse order");
for(int j=l-1;j>=0;j--)
 System.out.println("value="+v.elementAt(j));
}
}
}

