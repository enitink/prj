class First_Class
{
    int abc;
    int cde;
    static int efg;
    
    First_Class()
    {
        abc = 100;
        cde = 101;
    }
    
    First_Class(int abc, int cde)
    {
        this.abc = abc;
        this.cde = cde;        
    }
    
    void SetData(int abc, int cde)
    {
        this.abc = abc;
        this.cde = cde;
    }
    
    static void Nothing()
    {
        ++efg;
        System.out.println("Value of efg = " + efg);
    }
    
    void ShowData()
    {
        System.out.println("First_Class Value of abc = " + abc);
        System.out.println("First_Class Value of cde = " + cde);
    }
}

