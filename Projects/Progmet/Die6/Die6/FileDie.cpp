#include "FileDie.h"

using namespace std;

FileDie::FileDie(const string &FileName):
mInput(FileName.c_str())
{
	mInput >> mValue;
}

void FileDie::roll()
{
	mInput >> mValue;
	//Läser av tills sista värdet i en fil
	if (mInput.eof())
	{
		mInput.clear();
		mInput.seekg(0);
	}
}

int FileDie::read() const
{
	return mValue;
}