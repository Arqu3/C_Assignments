#ifndef INCLUDED_FILEDIE
#define INCLUDED_FILEDIE

#include "Die.h"
#include <fstream>

class FileDie : public Die
{
public:
	FileDie(const std::string &FileName);
	virtual void roll();
	virtual int read() const;

private:
	//Textfil input
	std::ifstream mInput;
	int mValue;
};

#endif