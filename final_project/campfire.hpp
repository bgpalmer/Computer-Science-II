#ifndef CAMPFIRE_HPP
#define CAMPFIRE_HPP

class Campfire
{
private:
        bool lit;
public:
        bool is_lit();
        bool light();

        Campfire();
        ~Campfire();
};

#endif
