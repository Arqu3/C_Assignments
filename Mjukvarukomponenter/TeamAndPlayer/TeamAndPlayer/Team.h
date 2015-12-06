#ifndef INCLUDED_TEAM
#define INCLUDED_TEAM

#include <string>

class Team
{
public:
	Team(const std::string &name);
	void setName(const std::string &name);
	const std::string getName() const;

private:
	std::string mName;
};

#endif