class test extends Exception
{
test(String x)
{
super(x);
} 
}

class exp7
{
public static int z;
public static void main(String xt[])
{
try
{
a();
}
catch(ArrayIndexOutOfBoundsException   ox)
{
System.out.println("array index out of bound invoke from main");
}

}
public static void a()
{
try
{
b();
}
catch(ArrayIndexOutOfBoundsException   ox)
{
System.out.println("array index out of bound invoke from a");
}

}
public static void b()
{
try
{
c();
}
catch(ArrayIndexOutOfBoundsException   ox)
{
System.out.println("array index out of bound invoke from b");
}
}
public static void c()
{
test o=new test("Array Index out of bound");
d();
if(z>=20)
{
try
{
throw o;
}
catch(test ox)
{
System.out.println("it is not possible  "+ox);
}
}
}
public static void d()
{
int a[]=new int[10];
for(int i=0;i<10;i++)
{
a[i]=i;
System.out.println("a["+i+"]="+a[i]);
}
z=20;
try
{
System.out.println(a[z]);
}
catch(ArrayIndexOutOfBoundsException   ox)
{
System.out.println("array index out of bound invoke from d");
}
}
}
