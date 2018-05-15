//
// Created by Павел Ганин on 15.05.2018.
//

#ifndef CHAIN_OF_KNOTS_COMMAND_H
#define CHAIN_OF_KNOTS_COMMAND_H

#include <string>

class Command
{
private:
    std::string name;
public:
    virtual void execute()=0;
    std::string getName(){
        return name;
    }
    Command(std::string _name){
        name = _name;
    }

};

#endif //CHAIN_OF_KNOTS_COMMAND_H
