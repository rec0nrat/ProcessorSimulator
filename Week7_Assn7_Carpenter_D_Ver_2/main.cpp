#include "Controller.h"

using namespace processor_sim;

void welcome();

int main(){

	welcome();

	cout << endl << "** Enter 'help' for a list of commands **\n" << endl;

	Control Processor;

	while (Processor.enterCommand()) {}

	system("pause");

	return 0;
}

void welcome() {

	cout << "Processor Simulation \n"
		<< "(Using MASM Instruction Set) \n"
		<< "Version 1.2 \n"
		<< endl;
}
