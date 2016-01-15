#include "Team.h"

using namespace std;

Team::Team(const string &name) :
mName(name)
{
}

void Team::setName(string &name)
{
	mName = name;
}

 string Team::getName() 
{
	return mName;
}