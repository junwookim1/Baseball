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

	int checkLength(const string& a, const std::string& b)
	{
		const int MAX = 60;
		size_t bigger = a.length();
		size_t smaller = b.length();

		if (bigger < smaller) swap(bigger, smaller);

		if (checkZero(bigger, smaller)) return result = 0;
		if (checkMax(bigger, smaller)) return result = MAX;
		return result = MAX - ((bigger - smaller) * MAX / smaller);
	}

	int getResult()
	{
		return result;
	}

private:
	int result = 0;
};
