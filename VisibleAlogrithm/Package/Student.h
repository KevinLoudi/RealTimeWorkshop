#pragma once

class _declspec(dllexport) Student
{
public:
	Student(void);
	~Student(void);
	bool SetAge(int iAge);
private:
	int m_age;
};
