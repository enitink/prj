class Exchange_No_Using_Bitwise_Operator
{
    public static void main(String[] args)
    {
        int a = 20, b = 10;
        System.out.println("Progrma for exchanging two numbers using ^ operator");
        System.out.println("a = " + a);      
        System.out.println("b = " + b);       
        System.out.println("Exchanging DATA");
        
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        
        System.out.println("Exchanged DATA");
        System.out.println("a = " + a);
        System.out.println("b = " + b);
     }
}