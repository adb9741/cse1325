#include <iostream>
#include <string.h>
#include <stdlib.h>  


using namespace std;

int main(){
string user = getenv("USER");

cout << "Hello, " << user << "!\n" << endl;
return 0;

}