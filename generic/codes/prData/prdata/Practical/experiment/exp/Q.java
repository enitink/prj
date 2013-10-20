interface p
{
final int x=10;
void m1();
}
interface p1 extends p
{
final int y=20;
void m2();
}
interface p2 extends p
{
final int z=30;
void m3();
}
interface p12 extends p1,p2
{
final int no=10;
void m4();
}
class Q implements p12
{
void m4()
{
System.out.println("CONSTANT OF INTERFACE P12="+no);
System.out.println("FROM INTERFACE P12");
}
void m3()
{
System.out.println("CONSTANT OF INTERFACE P2="+z);
System.out.println("FROM INTERFACE P2");
}
void m2()
{
System.out.println("CONSTANT OF INTERFACE P1="+y);
System.out.println("FROM INTERFACE P1");
}

void m1()
{
System.out.println("CONSTANT OF INTERFACE P="+x);
System.out.println("FROM INTERFACE P");
}
public static void main(String xt[])
{
Q o1=new Q();
o1.m1();
o1.m2();
o1.m3();
o1.m4();
}
}
