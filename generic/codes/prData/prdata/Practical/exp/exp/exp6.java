interface l1
{
    void m1();
}
interface l2
{
    void m2();
}
interface l3 extends l1,l2
{
    void m3();
}
interface l4
{
    void m4();
}
class w implements l3,l4
{
    public void m1()
    {
        System.out.println("method of interface l1");
    }

    public void m2()
    {
        System.out.println("method of interface l2");
    }
    
    public void m3()
    {
        System.out.println("method of interface l3");
    }
    
    public void m4()
    {
        System.out.println("method of interface l4");
    }
}

class exp6
{
    public static void main(String xt[])
    {
        w ob=new w();
        if(ob instanceof w)
        {
            System.out.println("ob is instance if class w");
            ob.m1();
            ob.m2();
            ob.m3();
            ob.m4();
        }
    }
}
