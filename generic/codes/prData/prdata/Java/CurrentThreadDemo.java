class CurrentThreadDemo{
	public static void main(String []args){
		
		Thread t = Thread.currentThread();		//returns Thread [ main, 5, main ]
		//Thread t = new Thread( Thread.currentThread() );	// returns Thread [ Thread-0, 5, main ]

		System.out.println( " Current thread t = " + t );
		System.out.println( " Current thread = " + t.getName() );

		t.setName("MyThread");
		System.out.println( " \nCurrent thread t = " + t );
		System.out.println( "  Current thread = " + t.getName() );

		try{
			for( int i = 65; i < 71; i++ ){
				System.out.println( " \ni = " + (char)i );
				//t.sleep(1000);
				Thread.sleep(1000);
			} 
		}

		catch( InterruptedException e ){
			System.out.println( e );
		}
	}
}

	