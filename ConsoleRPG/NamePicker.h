#pragma once

class NamePicker
{
public:
	static const int orcNameCount = 10;

private:
	static const char* orcNames[orcNameCount];
	//static const int i = 10;

public :
	inline static const char* GetOrcName(int index) 
	{ 
		if (index >= 0 && index < orcNameCount)
			return orcNames[index]; 
		return nullptr;
	}
};
