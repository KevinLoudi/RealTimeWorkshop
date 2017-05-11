#include "StdAfx.h"
#include "Student.h"

Student::Student(void)
{
}

Student::~Student(void)
{
}

bool Student::SetAge(int iAge)
{
	if (iAge<5 | iAge>50)
	{
		return false;
	}
	m_age=iAge;
	return true;
}
