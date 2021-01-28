class Bank{
	private:
		char name[39];
		char address[20];
		double ph;
		long int csn;
		char DOB[20];
		double dep;
		double withd;
		double amount;
		
	public:
		void menu();
		void new_acc();
		void check_an_acc();
		void edit();
		void transact();
		void erase();
		void see();
		
};
