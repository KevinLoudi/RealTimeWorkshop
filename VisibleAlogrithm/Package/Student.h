#pragma once

class _declspec(dllexport) Student
{
public:
	Student(void);
	~Student(void);
	bool SetAge(int iAge);

public:
	int m_number;
	int m_score;
private:
	int m_age;
};
