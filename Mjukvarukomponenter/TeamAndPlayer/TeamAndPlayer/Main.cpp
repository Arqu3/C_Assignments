#include "Connections.h"
#include "Player.h"
#include "Team.h"
#include <iostream>

using namespace std;

int main()
{
	Team *t0 = new Team("Team 0");
	Team *t1 = new Team("Team 1");

	Player *p0 = new Player("Player 0");
	Player *p1 = new Player("Player 1");

	Connections &connections = Connections::getInstance();

	connections.addPlayer(p0);
	connections.addPlayer(p1);

	connections.addTeam(t0);
	connections.addTeam(t1);

	connections.add(t0, p0);
	connections.add(t1, p1);
	connections.add(t0, p1);

	typedef Connections::Teams Teams;
	typedef Connections::Players Players;

	const Teams &teams = connections.getTeams();

	for (Teams::const_iterator ti = teams.begin(); ti != teams.end(); ti++)
	{
		Team *team = *ti;
		cout << team->getName() << endl;

		const Players &players = connections.getPlayers(team);

		for (Players::const_iterator pi = players.begin(); pi != players.end(); pi++)
		{
			Player *player = *pi;
			cout << " " << player->getName() << endl;
		}
	}

	connections.clear();

	system("Pause");

	return 0;
}