#include <iostream>

using namespace std;

class Time
{
	int hour;
	int min;
	int sec;
	int day;

public:
	Time(int h, int m, int s,int d)
	{
		hour = h;
		min = m;
		sec = s;
		day = d;
	}

	Time operator+(const Time& day2)
	{
		int t1, t2;
		t1 = this->hour * 60 * 60 + this->min * 60 + this->sec;
		t2 = day2.hour * 60 * 60 + day2.min * 60 + day2.sec;

		t1 = t1 + t2;
		int t1h, t1m, t1s;
		t1h = t1 / 3600;
		t1m = (t1 % 3600) / 60;
		t1s = (t1 % 3600) % 60;
		if (t1h/3600>=24)
		{
		return Time(t1h-24, t1m, t1s,1);
		}
		else
		{
			return Time(t1h, t1m, t1s, 0);
		}
	}

	Time operator-(const Time& day2)
	{
		int t1, t2;
		t1 = this->hour * 60 * 60 + this->min * 60 + this->sec;
		t2 = day2.hour * 60 * 60 + day2.min * 60 + day2.sec;

		t1 = t1 - t2;
		int t1h, t1m, t1s;
		t1h = t1 / 3600;
		t1m = (t1 % 3600) / 60;
		t1s = (t1 % 3600) % 60;
		if (t1<0)
		{
			return Time(23 + t1h, 60 + t1m, 60 + t1s, -1);
		}
		else
		{
			return Time(t1h, t1m, t1s, 0);
		}
	}

	bool operator<(const Time& day2)
	{
		int t1, t2;
		t1 = this->hour * 60 * 60 + this->min * 60 + this->sec;
		t2 = day2.hour * 60 * 60 + day2.min * 60 + day2.sec;

		t1 = t1 - t2;
		if (t1 < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>(const Time& day2)
	{
		int t1, t2;
		t1 = this->hour * 60 * 60 + this->min * 60 + this->sec;
		t2 = day2.hour * 60 * 60 + day2.min * 60 + day2.sec;

		t1 = t1 - t2;
		if (t1 > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator==(const Time& day2)
	{
		int t1, t2;
		t1 = this->hour * 60 * 60 + this->min * 60 + this->sec;
		t2 = day2.hour * 60 * 60 + day2.min * 60 + day2.sec;

		t1 = t1 - t2;
		if (t1 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend void print_time(const Time& day1);

	~Time()
	{}
};

void print_time(const Time& day1)
{
	if (day1.day ==1)
	{
		cout << "���� " << day1.hour << "�� " << day1.min << "�� " << day1.sec << "�� �Դϴ�." << endl;
	}
	else if (day1.day ==0)
	{
		cout << "���� " << day1.hour << "�� " << day1.min << "�� " << day1.sec << "�� �Դϴ�." << endl;
	}
	else
	{
		cout << "���� " << day1.hour << "�� " << day1.min << "�� " << day1.sec << "�� �Դϴ�." << endl;
	}
}

int main()
{
	Time first = Time(10, 0, 0,0 );
	Time result=Time(0,0,0,0);
	int h, m, s;

	cout << "�ð��� �Է��Ͻÿ� : " << endl;
	cin >> h >> m >> s;
	Time second(h, m, s,0);

	if (first < second)
	{
		cout << "first�� �̸� �ð��Դϴ�." << endl;
	}
	if (first > second)
	{
		cout << "second�� �̸� �ð��Դϴ�." << endl;
	}
	if (first == second)
	{
		cout << "first�� second�� ���� �ð��Դϴ�." << endl;
	}

	result = first + second;
	cout << "\n�� �ð��� ���� ����Ͻÿ� : " << endl;
	print_time(result);

	result = first - second;
	cout << "\n�� �ð��� ���� ����Ͻÿ� : " << endl;
	print_time(result);
	return 0;
}