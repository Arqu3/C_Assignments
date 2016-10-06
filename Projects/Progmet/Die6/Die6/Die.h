#ifndef INCLUDED_DIE
#define INCLUDED_DIE

class Die{

public:
	Die();
	virtual ~Die();

	virtual void roll() = 0;

	//Kan inte påverka värdet, endast läsa - const
	virtual int read() const = 0;

	enum Type 
	{
		D4,
		D6,
		D8,
		D10,
		D12,
		D20
	};

	//Static gör funktionen till en klassfunktion
	//static Die die4();
	//static Die die6();

private:
	//Medlemsvariabler o funktioner
	//Die(int max);
	Die(Type type);
	int randomValue(int value);
	int mValue;
	int mMax;

};

#endif