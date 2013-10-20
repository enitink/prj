class MyThread extends Thread {
	
	MyThread( String x ){
		
		super( x );
		System.out.println( " Name of the thread created : " + getName() );
		//System.out.println( " Current thread : " + Thread.currentThread() );
		//start();

	}
	
	public void run(){
	try{
		for( int i = 0; i < 5; i++ ){
			System.out.println( " \nName of the thread executing : " + getName() + " : i = " + i );
			sleep( 1000 );
		}
	}
	catch( InterruptedException e ){
		System.out.println( e );
	}
	}
}

class CallingSuperThreadDemo{
	public static void main( String []args){
		
		MyThread thread1 = new MyThread( " RAM " );
		 MyThread thread2= new MyThread( " KRISHNA " );

		thread1.start();
		thread2.start();		

	}
}
		