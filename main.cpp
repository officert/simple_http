#include <iostream>

#include "server.h"

using namespace std;

//function prototypes
// void validate_args(int argc, char* argv[]);
// void display_help();

int main(int argc, char* argv[]) {
	Server server;

	server.initServer();

	return 0;
}

// void validate_args(int argc, char* argv[]) {
// 	cout << "argc = " << argc << endl;
//    for(int i = 0; i < argc; i++)
//       cout << "argv[" << i << "] = " << argv[i] << endl;
// }
//
// void display_help() {
// 	cout << "--------------------------------" << endl;
// 	cout << "Server Util" << endl;
// 	cout << "--------------------------------" << endl;
// }
