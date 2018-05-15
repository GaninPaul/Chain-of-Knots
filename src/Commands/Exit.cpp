//
// Created by Павел Ганин on 15.05.2018.
//

#include "Exit.h"

Exit::Exit() : Command("Exit") {}


virtual void Exit::execute() {
    exit(-1);
}
