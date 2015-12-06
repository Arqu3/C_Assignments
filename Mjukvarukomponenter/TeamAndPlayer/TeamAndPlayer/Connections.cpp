#include "Connections.h"
#include "Player.h"
#include "Team.h"

using namespace std;

void Connections::addPlayer(Player *player)
{
	mPlayers.insert(player);
}

void Connections::addTeam(Team *team)
{
	mTeams.insert(team);
}

void Connections::add(Team *team, Player *player)
{
	mTeamToPlayers[team].insert(player);
	mPlayerToTeams[player].insert(team);
}

void Connections::remove(Team *team, Player *player)
{
	mTeamToPlayers[team].erase(player);
	mPlayerToTeams[player].erase(team);
}

void Connections::clear()
{
	internalClear();
}

Connections::Players& Connections::getPlayers()
{
	return mPlayers;
}

Connections::Players& Connections::getPlayers(Team *team)
{
	return mTeamToPlayers.find(team)->second;
}

Connections::Teams& Connections::getTeams()
{
	return mTeams;
}

Connections::Teams& Connections::getTeams(Player *player)
{
	return mPlayerToTeams.find(player)->second;
}

Connections& Connections::getInstance()
{
	static Connections connections;
	return connections;
}

Connections::Connections()
{
}

Connections::~Connections()
{
	internalClear();
}

void Connections::internalClear()
{
	mPlayerToTeams.clear();
	mTeamToPlayers.clear();

	while (!mPlayers.empty())
	{
		Player *player = *mPlayers.begin();
		mPlayers.erase(player);
		delete player;
	}

	while (!mTeams.empty())
	{
		Team *team = *mTeams.begin();
		mTeams.erase(team);
		delete team;
	}
}