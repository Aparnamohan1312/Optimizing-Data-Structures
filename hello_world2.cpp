#include <fstream>
#include <iostream>
int main(int argc, char *argv[])
{
    int total=0;
    char *endptr;
    for(int a=1;a<argc;a++){
        int b = std::strtol(argv[a], &endptr, 10);
        if (*endptr == '\0')
            total += b;}
	std::ofstream ofs ("hello.txt", std::ofstream::out);
	ofs << "Hello amoha121@ucr.edu! ";
    ofs << "The sum of your inputs is: " <<total;
	ofs.close();
	std::cout << "Execution Complete" << std::endl;
	return 0;  
}
