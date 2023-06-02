#include <string>

using namespace std;

class SimilarityChecker
{
public:
	void checkLength(const string& a, const std::string& b)
	{
		if (a == b || a.length() == b.length()) result = 60;
	}

	int getResult()
	{
		return result;
	}

private:
	int result = 0;
};
