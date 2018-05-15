//
// Created by Павел Ганин on 15.05.2018.
//

#ifndef CHAIN_OF_KNOTS_EXIT_H
#define CHAIN_OF_KNOTS_EXIT_H


#include "../Patterns/Command.h"

class Exit: public Command {
public:
    Exit();
    virtual void execute();
};


#endif //CHAIN_OF_KNOTS_EXIT_H
