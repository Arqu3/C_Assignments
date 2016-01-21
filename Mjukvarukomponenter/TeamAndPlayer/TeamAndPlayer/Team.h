#ifndef INCLUDED_TEAM
#define INCLUDED_TEAM

#include <string>

class Team
{
public:
	Team(const std::string &name);
	void setName(std::string &name);
	std::string getName();

private:
	std::string mName;
};

#endif