#include<iostream>

using std :: cin;
using std :: cout;
using std :: endl;

//Basic node class.
class LLNode
{
private:
	unsigned int p_data; //Data stored by the node. protected.
	LLNode* p_next;      //Pointer to the next node. protected.

public:
	LLNode() //Default Constructor
	{
		p_data = 0;    //No data.
		p_next = NULL; //New node always points to NULL by default.
	}
	LLNode(unsigned int data) //Constructor
	{
		p_data = data; //Set the data
		p_next = NULL; //New node always points to NULL by default.
	}
	unsigned int data(void) const //Retreive the data of the node. Constant function.
	{
		return p_data;
	}
	LLNode* next(void) const //Retreive the next point of the node. Constant function.
	{
		return p_next;
	}
	void setdata(unsigned int data) //Set the data of the node.
	{
		p_data = data;
	}
	void setnext(LLNode* next) //Set the next pointer of the node.
	{
		p_next = next;
	}

};

//Linked list class. Handles allocation, deallocation, and sorting of nodes.
class LList
{
private:
	LLNode* p_first; //First node in the list.

public:
	LList() //Constructor
	{
		p_first = NULL; //List contains no nodes by default.
	}
	~LList() //Destructor
	{
		LLNode* current = p_first; //Current node being pointed to.
		LLNode* deleting;          //Variable for storing the node to be deleted.

		while(current != NULL) //While current is not NULL, there are still more items in the list.
		{
			deleting = current;        //Store the current node to be deleted.
			current = current->next(); //Move to the next node.
			delete deleting;           //Delete the stored node.
		}
	}
	
	LLNode* first(void) const //Retreives the first node in the list. Constant function.
	{
		return p_first;
	}
	
	void additem(unsigned int data) //Add an item to the end of the list.
	{
		if(!p_first)                  //Make sure there are nodes in the list.
			p_first = new LLNode(data); //If there aren't make the first node.
		else                          //If there are items...
		{
			LLNode* current = p_first;     //Stores the current node.
			
			while(current->next() != NULL) //While there is a next node...
				current = current->next();   //Move to the next node.
			
			LLNode* prev = current;        //Store the current node.
			current = new LLNode(data);    //Make a new node.
			prev->setnext(current);        //Set the stored node to point to the new one.
		}
	}
	
	bool deleteitem(unsigned int data) //Delete an item from the list, based on its data.
	{
		if(p_first == NULL) //Make sure there are items in the list.
			return 0;         //If there aren't end the function now.
	
		LLNode* current = p_first; //Start with the first node.
	
		if(current->data() == data) //If the first node is the one we want...
		{
			p_first = current->next(); //Set p_first to NULL.
			delete current;            //Delete the node.
			return 1;                  //Success.
		}
	
		while(current->next() != NULL &&       //While there is a next node...
			current->next()->data() != data) //and it is not the one we want...
			current = current->next();           //Move to the next node.
	
		if(current->next() != NULL) //If the node was found.
		{
			LLNode* prev = current;         //Store the current node.
			current = current->next();      //Move to the node to be deleted.
			prev->setnext(current->next()); //Remove links to the node.
			delete current;                 //Delete the node.
			return 1;                       //Success.
		}
		return 0; //Failure.
	}
	
	LLNode* search(unsigned int data) //Search the list for a node with specified data.
	{
		LLNode* current = p_first; //Set the current node to the first.
		
		while(current != NULL)     //While current is not NULL, there are still more nodes.
		{
			if(current->data() == data) //If we have found the node, with the correct data...
				return current;           //return it.
			current = current->next();  //Otherwise, move to the next node and continue.
		}
		return NULL; //If we never found the node, return NULL.
	}
	
	bool insertitem(unsigned int prevdata, unsigned int data) //Insert a new node after a node with specified data.
	{
		LLNode* prev = search(prevdata); //Find the node with the specified data.
		
		if(prev == NULL)                 //If the node was not found...
			return 0;                      //We did not succeed.
	
		LLNode* next = prev->next();        //Store the next node.
		LLNode* current = new LLNode(data); //Make the new node.
		prev->setnext(current);             //Set the previous node to point to the new one.
		current->setnext(next);             //Set the new node to point to the next one.
		
		return 1; //We did succeed.
	}
	void insertfirst(unsigned int data) //Insert a new node as the first node.
	{
		LLNode* current = new LLNode(data); //Create the new node.
		current->setnext(p_first);          //Make the current node point to the old first node.
		p_first = current;                  //Set p_first to the current node.
	}
	
	void display_data(void)
	{
		LLNode* Temp = p_first;
		
		cout << endl << "Contents of Data : ";
		while(Temp != NULL)
		{
			cout << Temp->data() << " ";
			Temp = Temp->next();
		}
	}
};

int main()
{
	LList Link_List;
	char ans = 'y';
	unsigned int n;
	
	while(tolower(ans) != 'n')
	{
		cout << endl << "Enter Data to Enter : ";
		cin >> n;
		Link_List.additem(n);
		
		cout << endl << "Do U want to Continue(y/n)";
		cin >> ans;
	}
	
	Link_List.display_data();
	
	
	cout << endl;
	
	return 0;
}