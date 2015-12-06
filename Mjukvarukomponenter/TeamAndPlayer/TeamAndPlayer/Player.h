#ifndef INCLUDED_PLAYER
#define INCLUDED_PLAYER

#include <string>

class Player
{
public:
	Player(const std::string &name);
	void setName(const std::string &name);
	const std::string getName() const;

private:
	std::string mName;
};

#endif