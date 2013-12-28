class Third_Class
{
    int abc;
    int cde;
    
    Third_Class()
    {        
        abc = 301;
        cde = 302;
    }
    
    Third_Class(int abc, int cde)
    {
        this.abc = abc;
        this.cde = cde;
    }
    
    void ShowData()
    {
        System.out.println("third_Class Value of abc = " + abc);
        System.out.println("third_Class Value of cde = " + cde);
    }
    
}