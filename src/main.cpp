#include <iostream>

#include "http_client.h"

using namespace std;

//function prototypes
void validate_args(int argc, char* argv[]);
// void display_help();

int main(int argc, char* argv[]) {
	HttpClient httpClient;
	std::string response;

	try {
		validate_args(argc, argv);
	} catch(const char* exception) {
		cout << "Error : " << exception << endl;

		return 1;
	}

	std::string address = argv[1];

	try {
		response = httpClient.get(address);

		cout << endl << response << endl;
	} catch (const char* exception) {
		cout << "Error : " << exception << endl;
	}

	return 0;
}

void validate_args(int argc, char* argv[]) {
	// cout << "argc = " << argc << endl;

  // for(int i = 0; i < argc; i++)
	// {
	// 	cout << "argv[" << i << "] = " << argv[i] << endl;
	// }

	if(argc < 2)
	{
		throw "Must pass arg a";
	}
}
