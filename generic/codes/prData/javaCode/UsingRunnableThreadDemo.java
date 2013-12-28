class MyThread implements Runnable {
	
	/*MyThread( String x ){
		super( x );
		//start();
	}*/
	
	public void run(){
	try{
		for( int i = 0; i < 5; i++ ){
			System.out.println( " i = " + i );
			//this.sleep( 2000 );
		}
	}
	catch( Exception e ){
		System.out.println( e );
	}
	}
}

class UsingRunnableThreadDemo{
	public static void main( String []args){
		
		MyThread thread1 = new MyThread();
		Thread thread3 = new Thread( thread1, " RAM" );

		 MyThread thread2= new MyThread();
		Thread thread4 = new Thread( thread2, " HANUMAN " );

		thread3.start();
		thread4.start();		

	}
}
		