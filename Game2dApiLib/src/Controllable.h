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
	// Os inputs e comandos irão ficar armazenados no objeto Controllable
	// Eles devem ser referência por causa que Input e Command são classes polimórficas e virtuais puras
	//		STL não lida bem com polimorfismo
	//		Perigo dos objetos sairem do escopo onde foram criadas e deixarem referências inválidas no map
	// Solução: map deve copiar os inputs e commandos e armazenar referências para estas cópias
	//		Perigo de só copiar a parte da classe base e não o objeto completo!!!
	//		Ponto negativo é que vai usar muito a Heap, e criar muitas cópias desnecessárias do mesmo Input
	//		Ou declara tudo no começo, na stack mesmo e guarda a referência para a stack. Só tem que dar um jeito de garantir isso: que será declarado os inputs e comandos no começo
	//		Parecido com as imagens, elas devem ser criadas no começo e guardar várias referências para as poucas imagens criadas.
}

#endif // _CONTROLLABLE_