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

	static bool instantiated;	// Vai dar errado várias classes herdando isso!
								// Um membro estático para vários objetos (GraphManager, InputManager, InputGetter...)
};


#endif // _UNIQUE_