#include <iostream>

#include "http_client.h"

using namespace std;

//function prototypes
void validate_args(int argc, char* argv[]);
// void display_help();

int main(int argc, char* argv[]) {
	HttpClient httpClient;
	std::string response;

	cout << "ARGS" << endl;
	validate_args(argc, argv);
	cout << endl;

	const std::string address = argv[1];

	try {
		cout << "address " << address << endl;

		response = httpClient.get(address);

		cout << endl << response << endl;
	} catch (const char* exception) {
		cout << "Error : " << exception << endl;
	}

	return 0;
}

void validate_args(int argc, char* argv[]) {
	cout << "argc = " << argc << endl;
   for(int i = 0; i < argc; i++)
      cout << "argv[" << i << "] = " << argv[i] << endl;
}

//
// void display_help() {
// 	cout << "--------------------------------" << endl;
// 	cout << "Server Util" << endl;
// 	cout << "--------------------------------" << endl;
// }
