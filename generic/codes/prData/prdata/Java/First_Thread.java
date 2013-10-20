class First_Thread extends Thread
{
    public void run()
    {
        for(long i = 0l; i < 1000000000; ++i)
        {
            System.out.print(" " + i);
            for(long j = 0l; j < 100; ++j)
            {}
        }
    }
}