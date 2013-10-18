#include	<gQueue.h>

using namespace gen::ds::queue;
 
int main()
{
	gQueue <int> Que(200);
	int n;
	char ans = ' ';
	
	while(tolower(ans) != 'n')
	{
		cout << endl << "Enter Data to Push : ";
		cin >> n;
		Que.InsertData(n);
		
		cout << endl << "Do U want to Continue(y/n)";
		cin >> ans;
	}
	
	cout << "Getting Data out of Que :";
	while(Que.MoreData())
	{
		cout << "  " << Que.GetData();
	}
	
	cout << endl;
	return 0;
}
