#include <iostream>

using namespace std;

class Time
{
	int hour;
	int min;
	int sec;

public:
	Time(int h , int m, int s)
	{
		hour= h;
		min = m;
		sec = s;
	}

	Time operator=( const Time& day2)
	{
		this->hour = day2.hour;
		this->min = day2.min;
		this->sec= day2.sec;

		return *this;
	}

	friend Time operator+(const Time& day1, const Time& day2);
	friend Time operator-(const Time& day1, const Time& day2);

	bool operator<(const Time& day2)
	{
		int t1, t2;
		t1 = this->hour * 60 * 60 + this->min * 60 + this->sec;
		t2 = day2.hour * 60 * 60 + day2.min * 60 + day2.sec;

		t1 = t1 - t2;
		if (t1<0)
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
		t1 = this ->hour * 60 * 60 + this->min * 60 + this->sec;
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

Time operator+(const Time& day1, const Time& day2)
{
	int t1, t2;
	t1 = day1.hour * 60 * 60 + day1.min * 60 + day1.sec;
	t2 = day2.hour * 60 * 60 + day2.min * 60 + day2.sec;

	t1 = t1 + t2;
	int t1h, t1m, t1s;
	t1h = t1 / 3600;
	t1m = (t1 % 3600) / 60;
	t1s = (t1 % 3600) % 60;

	return Time(t1h, t1m, t1s);
}

Time operator-(const Time& day1, const Time& day2)
{
	int t1, t2;
	t1 = day1.hour * 60 * 60 + day1.min * 60 + day1.sec;
	t2 = day2.hour * 60 * 60 + day2.min * 60 + day2.sec;

	t1 = t1 - t2;
	int t1h, t1m, t1s;
	t1h = t1 / 3600;
	t1m = (t1 % 3600) / 60;
	t1s = (t1 % 3600) % 60;

	return Time(t1h, t1m, t1s);
}

void print_time(const Time& day1)
{
	int t1;
	t1 = day1.hour * 60 * 60 + day1.min * 60 + day1.sec;
	int t1h, t1m, t1s;
	t1h = t1 / 3600;
	t1m = (t1 % 3600) / 60;
	t1s = (t1 % 3600) % 60;
	if (t1<0)
	{
		t1 = (24 * 60 * 60) + t1;
		t1h = t1 / 3600;
		t1m = (t1 % 3600) / 60;
		t1s = (t1 % 3600) % 60;

		cout << "���� " << t1h << "�� " << t1m << "�� " << t1s << "�� �Դϴ�."<<endl;
	}
	else if (t1h>=24)
	{
		cout << "���� " << t1h-24 << "�� " << t1m << "�� " << t1s << "�� �Դϴ�."<<endl;
	}
	else
	{
		cout << "���� " << t1h << "�� " << t1m << "�� " << t1s << "�� �Դϴ�."<<endl;
	}
}

int main()
{
	Time first = Time(10, 0, 0);
	Time result=Time(0,0,0);
	int h, m, s;

	cout << "�ð��� �Է��Ͻÿ� : " << endl;
	cin >> h >> m >> s;
	Time second(h, m, s);

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
	cout << "\n�� �ð��� ���� ����Ͻÿ� : "<<endl;
	print_time(result);

	result = first - second;
	cout << "\n�� �ð��� ���� ����Ͻÿ� : " <<endl;
	print_time(result);
	return 0;
}