import java.math.*;

class Ex1
{
    public static void main(String args[])
    {
        int i, j;
        int twoD[][] = new int[3][3];

        for (i=0; i<3; i++)
            for(j=0; j<3; j++)
                twoD[i][j] = (int)(Math.pow((double)10.0, (double)i));
        
        for (i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
                System.out.println("twoD[" + i + "][" + j + "] = " + twoD[i][j]);
            System.out.println(" ");
            System.out.println("Length of twoD[" + i + "] = " + twoD[i].length);
            System.out.println(" ");
        }
    }
}
