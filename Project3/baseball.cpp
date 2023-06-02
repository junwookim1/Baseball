#include <stdexcept>
#include <string>

using namespace std;

struct Result
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	Baseball(string q) : question(q)
	{
	}


	bool isIncludeChar(string guessNumber)
	{
		for (const auto& ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9') continue;
			return true;
		}
		return false;
	}

	bool isDuplicated(string guessNumber)
	{
		if (guessNumber[0] == guessNumber[2])
			return true;
		return false;
	}

	void assertInvalidArgment(string guessNumber)
	{
		if (guessNumber == "")
		{
			throw std::invalid_argument("값을 넣어야함");
		}
		else if (guessNumber.length() != 3)
		{
			throw std::invalid_argument("자리수 오류");
		}
		else if (isIncludeChar(guessNumber))
		{
			throw std::invalid_argument("숫자가 아닌 것이 포함됨");
		}
		else if (isDuplicated(guessNumber))
		{
			throw std::invalid_argument("중복된 숫자가 포함됨");
		}
	}

	int getBallCount(string guessNumber)
	{
		int result = 0;
		for (int i = 0; i < 3; i++)
		{
			int index = question.find(guessNumber[i]);
			if (index == -1)continue;
			if (index == i) continue;
			result++;
		}
		return result;
	}
	int getStrikeCount(string guessNumber)
	{
		int result = 0;
		for (int i = 0; i < 3; i++)
		{
			int index = question.find(guessNumber[i]);
			if (index == -1)continue;
			if (index != i) continue;
			result++;
		}
		return result;
	}

	Result guess(string guessNumber)
	{
		assertInvalidArgment(guessNumber);
		//핵심 로직 구현

		if (guessNumber == question) {
			return { true, 3, 0 };
		}

		bool solved = false;
		int strikes = getStrikeCount(guessNumber);
		int balls = getBallCount(guessNumber);
		return { solved , strikes, balls };
	}

private:
	string question;
};
