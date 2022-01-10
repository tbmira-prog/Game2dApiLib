#ifndef _CONTROLLABLE_
#define _CONTROLLABLE_

#include <functional>
#include <unordered_map>
#include <vector>

#include "Command.h"
#include "Input.h"

namespace input
{
	class Controllable
	{
	public:
		Controllable();
		~Controllable();

		void HandleInput(const std::reference_wrapper <Input> input);

		void SetCommandInput(std::reference_wrapper <Input> input, std::reference_wrapper <Command> command);

	private:
		std::unordered_map < std::unordered_map<std::reference_wrapper<Input>&, std::reference_wrapper<Command>& > commandMap; //std::unordered_map<std::reference_wrapper<Input>, std::reference_wrapper<Command>> commandMap;
	};
	// Os inputs e comandos ir�o ficar armazenados no objeto Controllable
	// Eles devem ser refer�ncia por causa que Input e Command s�o classes polim�rficas e virtuais puras
	//		STL n�o lida bem com polimorfismo
	//		Perigo dos objetos sairem do escopo onde foram criadas e deixarem refer�ncias inv�lidas no map
	// Solu��o: map deve copiar os inputs e commandos e armazenar refer�ncias para estas c�pias
	//		Perigo de s� copiar a parte da classe base e n�o o objeto completo!!!
	//		Ponto negativo � que vai usar muito a Heap, e criar muitas c�pias desnecess�rias do mesmo Input
	//		Ou declara tudo no come�o, na stack mesmo e guarda a refer�ncia para a stack. S� tem que dar um jeito de garantir isso: que ser� declarado os inputs e comandos no come�o
	//		Parecido com as imagens, elas devem ser criadas no come�o e guardar v�rias refer�ncias para as poucas imagens criadas.
}

#endif // _CONTROLLABLE_