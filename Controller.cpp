#include "Controller.h"

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::displayLogin()const
{
	string input;
	bool cont = true;
	cout << "Are you a CUStomer or a Merchant? [CM]" << endl;
	cin >> input;
	char c = input[0];
	while(cont)
	{
		switch(c)
		{
			case 'c':
			case 'C':
				cont = false; 
				customerLogin();
				break;
			case 'm':
			case 'M':
				cont = false; 
				merchantLogin();
				break;
			default:
				cout << "Please type either C or M." << endl;
				cin >> input;
				c = input[0];	
				break;
		}
	}
}

void Controller::displayCustomerLogin() const
{
	string input;
	bool cont = true; 
	cout << "New or Returning User? [NR]" << endl;
	cin >> input;
	char c = input[0];
	while(cont)
	{
		switch(c)
		{
			case'r':
			case'R':
				cont = false;
				string username, password;
				cout << "Enter your Username" << endl;
				cin >> username;
				cout << "Enter your Password" << endl;
				cin >> password; 
				this -> customerLogin(username, password);
				break;
			case 'n':
			case 'N':
				cont = true;
				this -> createCustomer();
				break;
			default:
				cout << "Please type either N or R." << endl;
				cin >> input;
				c = input[0];
				break;
		}
	}
}

Customer::Customer* Controller::customerLogin(const std::string& username, const std::string& password)
{
	if(this -> getCustomer(username) == NULL)
	{
		return NULL;
	}
	else
	{
		Customer* customer = this -> getCustomer(username);
		this -> setUsername(customer -> getUsername());
	}
}

Customer::Customer* Controller::createCustomer()
{
	int id, zip, money;
	std::string username, password, fullName, address, city, state;

	id = myCustomers.size() + 1;

	std::cout << "Username: ";
	std::cin >> username;
	std::cout << "Password: ";
	std::cin >> password;
	std::cout << "Full name: ";
	std::cin >> fullName;
	std::cout << "Address: ";
	std::cin >> address;
	std::cout << "City: ";
	std::cin >> city;
	std::cout << "State: ";
	std::cin >> state;
	std::cout << "Zip code: ";
	std::cin >> zip;
	std::cout << "Starting balance: ";
	std::cin >> money;

	Customer::Customer* customer = new Customer(id, username, password, fullName, address, city, state, zip, money);
	myCustomers.push_back(customer);
}

void Controller::merchantLogin() const
{
        string input;
        bool cont = true;
        cout << "Enter Username" << endl;
        cin >> input;
        map<string, Merchant*>::const_iterator itr;
        itr = merchants.find(input);
        if (itr == merchants.end()) {
                cout << "Invalid Username" << endl;
        } else {
                string input2;
                Merchant m = *(itr->second);
                string password = m.getPassword();
                cout << "Enter Password" << endl;
                cin >> input2
                if( input2 == password) {
                        cout << "Welcome back, " << input << "You can Add/change inventory price, List inventory, Remover inventory, Display orders by customer ID, or show inventory Categories.[ALRDC]" << endl;;
                } else {
                        cout << "Invalid Password" << endl;
                }

        }
}


Customer::Customer* Controller::getCustomer(const std::string& username)
{
	for(int i = 0; i < myCustomers.size(); i++)
	{
		if(myCustomers.at(i) -> getUsername() == username)
			return myCustomers.at(i);
	}
	return NULL;
}

Merchant::Merchant* Controller::getMerchant(const std::string& username)
{
}

void Controller::setUsername(const std::string& username)
{
	myUsername = username;
}

const std::string& Controller::getUsername() const
{
	return myUsername;
}

