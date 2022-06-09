#include <iostream>
#include <cstdlib>

int main(){

    std::cout << "-----------------welcome to Nodawa, ready to backup some stuff ? ------------------" <<std::endl;

    std::cout << "-----------------------------------------------------------------------------------" <<std::endl;
    
    std::cout << "----HINT:please make sure that you have twrp installed, it is neccessary.----------" <<std::endl;
    
    std::cout << "-1-starting the work, please enable usb debugging and connect your cable, then press enter.";
    
    getchar();
    system("adb devices");

    std::cout << "-2-please allow the connection and press enter." ;
    
    getchar();

    std::cout << "-3- rebooting to recovery..." << std::endl;
    
    system("adb reboot recovery");
    
    std::cout << std::endl;

    std::cout << "-4-Your phone rebooted to recovery." << std::endl;
    
    std::cout << std::endl;

    std::cout << "-5- please enter how many partitions did you chose:";

    int partitionsCounter;

    std::cin >> partitionsCounter;
    
    std::string paritions[partitionsCounter];

    for (int i = 0; i < partitionsCounter; i++)
    {
        std::cout << "-6- now you need to enter the chosen partitions names(lower case only!)." << std::endl;
        std::cout << "-6." << i << "-enter partition " << i << " name: ";
        std::cin >> paritions[i];
    }

    std::cout << "-7- backup of partitions in progress be patient." << std::endl;

    for (int i = 0; i < partitionsCounter; i++)
    {
        std::cout << "-7." << i <<"-pulling " << paritions[i] << " in progress." << std::endl;
        std::string fullCommand = "adb pull /dev/block/by-name/"+ paritions[i]+" "+paritions[i]+".img";
        system(fullCommand.c_str());
        
        std::cout << "-7." << i <<"-Done pulling "+paritions[i] << std::endl;

    }
    
    std::cout << std::endl;
    std::cout << "Backup has been completed!" << std::endl;    
    
}