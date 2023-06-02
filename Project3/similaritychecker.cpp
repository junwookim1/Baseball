#include <string>
#include <set>
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
		int sameCnt = 0;
		int totalCnt = 0;

		set<char> sa;
		for (const auto& ch : a)
		{
			sa.insert(ch);
		}

		set<char> sb;
		for (const auto& ch : b)
		{
			sb.insert(ch);
		}

		for (const auto& ch_b : sa)
		{
			auto it = sb.find(ch_b);
			if (it != sb.end()) sameCnt++;
		}
		totalCnt = sa.size() + sb.size() - sameCnt;

		result = sameCnt * MAX / totalCnt;
	}

	int getResult()
	{
		return result;
	}

private:
	int result = 0;
};
