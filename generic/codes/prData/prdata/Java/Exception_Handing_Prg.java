import java.io.*;

class Exception_Handing_Prg
{
    public static void main(String [] agrs) throws Exception
    {
        int x;
        int y;
        int Arr[] = new int [3];
        String d;
        
        InputStreamReader i = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(i);
        
        System.out.println("Enter Value of X : ");
        d = br.readLine();
        x = Integer.parseInt(d);
        
        System.out.println("Enter Value of Y : ");
        d = br.readLine();
        y = Integer.parseInt(d);
        
        try
        {
            x = x / y;
            if (y == 10)
                throw new ExceptionCl();
        }
        catch(ArithmeticException e)
        {
            System.out.println("Divide By Zero Error");            
        }
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.out.println("Index Out of Bound Order");
        }
        catch(ExceptionCl e)
        {
            System.out.println(e);
        }
        finally
        {
            System.out.println("I am in Finally");
        }
        System.out.println("I am out of try block");
    }
}