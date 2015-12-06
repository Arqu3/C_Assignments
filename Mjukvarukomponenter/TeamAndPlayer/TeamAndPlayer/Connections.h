#ifndef INCLUDED_CONNECTIONS
#define INCLUDED_CONNECTIONS

#include <set>
#include <map>

class Team;
class Player;

class Connections
{
public:
	typedef std::set<Player*> Players;
	typedef std::set<Team*> Teams;

	void addPlayer(Player *player);
	void addTeam(Team *team);

	void add(Team *team, Player *player);
	void remove(Team *team, Player *player);

	void clear();

	Players& getPlayers();
	Players& getPlayers(Team *team);
	Teams& getTeams();
	Teams& getTeams(Player *player);

	static Connections& getInstance();

private:
	typedef std::map<Team*, Players> TeamToPlayers;
	typedef std::map<Player*, Teams> PlayerToTeams;

	Connections();
	Connections(const Connections &connections);
	~Connections();

	void internalClear();
	Connections& operator=(const Connections &conncetions);

	Teams mTeams;
	Players mPlayers;
	TeamToPlayers mTeamToPlayers;
	PlayerToTeams mPlayerToTeams;
};

#endif