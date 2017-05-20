#include "Gamefiles/Engine/Framework.hpp"

int main()
{
	std::cout << "----------------------------------------------------------------------------------------" 
			  << std::endl;
	Framework frmwrk("Space Future");

	frmwrk.run();

	return 0;
}