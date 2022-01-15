#ifndef _UNIQUE_
#define _UNIQUE_

class Unique
{
public:
	Unique();
	virtual ~Unique();

private:
	Unique(const Unique&);
	Unique& operator=(const Unique&);

	static bool instantiated; // TODO Arrumar classe Unique para que vário Managers possam derivar dela 
};


#endif // _UNIQUE_