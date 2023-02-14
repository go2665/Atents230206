#pragma once

class NamePicker
{
public:
	static const int orcNameCount = 10;
	static const int wolfNameCount = 5;

private:
	static const char* orcNames[orcNameCount];
	static const char* wolfNames[wolfNameCount];
	//static const int i = 10;

public :
	inline static const char* GetOrcName(int index) 
	{ 
		if (index >= 0 && index < orcNameCount)
			return orcNames[index]; 
		return nullptr;
	}

	inline static const char* GetWolfName(int index)
	{
		if (index >= 0 && index < wolfNameCount)
			return wolfNames[index];
		return nullptr;
	}
};
