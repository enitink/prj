class Factorial
{
    public static long FindFactorial(long Factorial)
    {
        return (Factorial == 0) ? 1 : (Factorial * FindFactorial(--Factorial));        
    }
    public static void main(String[] args)
    {
        long Factorial = 0l;
        System.out.println("Program to print Fatorial of 5!");
        Factorial = FindFactorial(5);
        System.out.println("Factorial = " + Factorial); 
    }    
}