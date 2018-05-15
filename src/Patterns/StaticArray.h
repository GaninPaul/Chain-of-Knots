//
// Created by Павел Ганин on 15.05.2018.
//

#ifndef CHAIN_OF_KNOTS_STATICARRAY_H
#define CHAIN_OF_KNOTS_STATICARRAY_H

template <typename contentType, int count>
struct StaticArray
{
    contentType data[count];

    contentType& operator [](int i) {return data[i];}
    contentType* ptr() {return data;}
};

#endif //CHAIN_OF_KNOTS_STATICARRAY_H
