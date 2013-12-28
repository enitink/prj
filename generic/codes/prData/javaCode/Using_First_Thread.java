class Using_First_Thread
{
    public static void main(String [] args)
    {
        First_Thread Th1 = new First_Thread();
        First_Thread Th2 = new First_Thread();
        
        Th1.start();
        Th2.start();
    }
}