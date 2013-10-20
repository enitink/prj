class Second_Class
{
    int abc;
    int cde;
    
    Second_Class()
    {        
        abc = 201;
        cde = 202;
    }
    
    Second_Class(int abc, int cde)
    {
        this.abc = abc;
        this.cde = cde;
    }
    
    void ShowData()
    {       
        System.out.println("Second_Class Value of abc = " + abc);
        System.out.println("Second_Class Value of cde = " + cde);
    }
}