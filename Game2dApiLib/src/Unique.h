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

	static bool instantiated;	// Vai dar errado v�rias classes herdando isso!
								// Um membro est�tico para v�rios objetos (GraphManager, InputManager, InputGetter...)
};


#endif // _UNIQUE_