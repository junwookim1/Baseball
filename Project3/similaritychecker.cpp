#include <string>

using namespace std;

class SimilarityChecker
{
public:
	void checkLength(const string& a, const std::string& b)
	{
		size_t bigger = a.length();
		size_t smaller = b.length();
		if (bigger < smaller) swap(bigger, smaller);

		if (bigger >= smaller * 2) result = 0;
		else if (a == b || a.length() == b.length()) result = 60;
	}

	int getResult()
	{
		return result;
	}

private:
	int result = 0;
};
