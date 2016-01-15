#ifndef INCLUDED_PLAYER
#define INCLUDED_PLAYER

#include <string>

class Player
{
public:
	Player(const std::string &name);
	void setName(std::string &name);
	std::string getName();

private:
	std::string mName;
};

#endif