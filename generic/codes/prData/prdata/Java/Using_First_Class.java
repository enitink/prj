class Using_First_Class
{
    public static void main(String[] args)
    {
        System.out.println("Here is the First Object of First Class");
        First_Class Object1 = new First_Class();
        First_Class.Nothing();
        Object1.ShowData();
        Object1.SetData(1001, 1002);
        Object1.ShowData();
        
        System.out.println("Here is the Second Object of First Class");
        First_Class Object2 = new First_Class(1001, 1002);
        First_Class.Nothing();
        Object2.ShowData();
        Object2.SetData(2001, 2002);
        Object2.ShowData();
        
        System.out.println("Here is the First Objec of Second Class");
        Second_Class Object3 = new Second_Class();
        Object3.Nothing();
        Object3.ShowData();
        Object3.SetData(3001, 3002);
        Object3.ShowData();
        
        System.out.println("Here is the Second Object of Second Class");
        Second_Class Object4 = new Second_Class(4000, 4001);
        Object4.Nothing();
        Object4.ShowData();
        Object4.SetData(4001, 4002);
        Object4.ShowData();
        
        System.out.println("Here is the First Objec of third Class");
        Second_Class Object5 = new Second_Class();
        Object5.Nothing();
        Object5.ShowData();
        Object5.SetData(5001, 5002);
        Object5.ShowData();
        
        System.out.println("Here is the Second Object of third Class");
        Second_Class Object6 = new Second_Class(4000, 4001);
        Object6.Nothing();
        Object6.ShowData();
        Object6.SetData(6001, 6002);
        Object6.ShowData();    
        
    }
}