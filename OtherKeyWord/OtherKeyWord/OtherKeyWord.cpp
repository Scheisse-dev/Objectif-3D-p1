#include <iostream>
#include <vector>


enum Axis
{
    X = 1000,
    Y //= 1
};

class Entity
{
public:
    virtual ~Entity()
    {

    }
};

class Player : public Entity
{
public:
    Player() = default; 
}; 

int main()
{
    /*
    std::vector<Entity*> _entities = std::vector<Entity*>(); 
    _entities.push_back(new Entity()); 
    _entities.push_back(new Player()); 

    for (int i = 0; i < _entities.size(); i++)
    {
        Entity* _entity = _entities[i];
        Player* p = dynamic_cast<Player*>(_entity); 
        if (p != nullptr)
            std::cout << "Is Player" << std::endl; 
    }
    
    Axis _axis = Axis::X;
    if (_axis == Axis::X)
    {

    }
    else if (_axis == Axis::Y)
    {

    }
    switch (_axis)
    {
    case Axis::X: 
    {
        std::cout << "X" << std::endl;
        break; 
    }
    case Axis::Y: 
    {
        std::cout << "Y" << std::endl;
        break; 
    }
    default:
        std::cout << "Default" << std::endl; 
        break; 
    }
    */
}
