#ifndef INCLUDED_DIE
#define INCLUDED_DIE

struct Die;

Die* CreateDie(int max);
void DestroyDie(Die *die);

void Roll(Die *die);
int Read(const Die *die);

#endif // !INCLUDED_DIE


