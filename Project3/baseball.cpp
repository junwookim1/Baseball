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
			throw std::invalid_argument("���� �־����");
		}
		else if (guessNumber.length() != 3)
		{
			throw std::invalid_argument("�ڸ��� ����");
		}
		else if (isIncludeChar(guessNumber))
		{
			throw std::invalid_argument("���ڰ� �ƴ� ���� ���Ե�");
		}
		else if (isDuplicated(guessNumber))
		{
			throw std::invalid_argument("�ߺ��� ���ڰ� ���Ե�");
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
		//�ٽ� ���� ����

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
