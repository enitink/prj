class Check_Instance_Of
{
    void showdata(Object ob)
    {
        if(ob instanceof First_Class)
        {
            System.out.println("Instance of First Class:");
            ob.ShowData();
        }
    }
}