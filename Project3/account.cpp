class Account
{
public:
	explicit Account(int bal) :balance(bal) {}

	int getBalance()
	{
		return balance;
	}
private:

	int balance;
};