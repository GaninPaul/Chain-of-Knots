//
// Created by Павел Ганин on 15.05.2018.
//

#ifndef CHAIN_OF_KNOTS_SINGLETON_H
#define CHAIN_OF_KNOTS_SINGLETON_H

template <class t_class>
class Singleton
{
public:

    static t_class& instance()
    {
        static t_class _instance;
        return _instance;
    }

protected:
    Singleton(){};
    Singleton(const Singleton&){};
    Singleton& operator = (const Singleton&){};

};

#endif //CHAIN_OF_KNOTS_SINGLETON_H
