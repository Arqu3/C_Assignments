#include "Team.h"

using namespace std;

Team::Team(const string &name) :
mName(name)
{
}

void Team::setName(const string &name)
{
	mName = name;
}

const string Team::getName() const
{
	return mName;
}