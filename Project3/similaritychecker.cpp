#include <string>

using namespace std;

class SimilarityChecker
{
public:
	bool checkZero(size_t bigger, size_t smaller)
	{
		return bigger == 0 || smaller == 0 || bigger >= smaller * 2;
	}

	bool checkMax(size_t bigger, size_t smaller)
	{
		return bigger == smaller;
	}

	void checkLength(const string& a, const std::string& b)
	{
		const int MAX = 60;
		size_t bigger = a.length();
		size_t smaller = b.length();

		if (bigger < smaller) swap(bigger, smaller);

		if (checkZero(bigger, smaller)) result = 0;
		else if (checkMax(bigger, smaller)) result = MAX;
		else
		{
			result = MAX - ((bigger - smaller) * MAX / smaller);
		}
	}

	void checkAlpha(const string& a, const std::string& b)
	{
		const int MAX = 40;
		size_t bigger = a.length();
		size_t smaller = b.length();

		if (bigger < smaller) swap(bigger, smaller);
		result = 40;
	}

	int getResult()
	{
		return result;
	}

private:
	int result = 0;
};
