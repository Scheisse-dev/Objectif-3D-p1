#include <iostream>
#include "Mob.h"
#include "Inventory.h"
#include "Utils.h"
#include "Vector2.h"
#include "Map.h"

//bah c'est player mais version mob https://tenor.com/view/genius-think-be-clever-be-smart-gif-10617231
// bon bah ça crash pas c'est déjà bien
Mob::Mob(const std::string& _name, Vector2* _position, const float _maxLife, const float _maxMana) // déclaration du mob héritant de entity
    :Entity(_name, _position, _maxLife, _maxMana)
{
    inventory = new Inventory(_name + "Inventory", this);  // déclaration de l'inventaire du mob car bon bah il doit loot un truc, enfin je crois 
}

Mob::Mob(const Mob& _copy)
{
    inventory = _copy.inventory; 
}

Mob::~Mob()
{
    delete inventory; 
}

Inventory* Mob::GetInventory() const
{
    return inventory;
}

void Mob::Move()
{
    
    Vector2 _position = *Position();
    int _rand;
    srand((unsigned int)time(NULL)); // déclaration du random qui permet une avancée aléatoire du mob d'une case 
    for (size_t i = 0; i < 4; i++)
    {
        _rand = rand() % 4; 
    }
    if (_rand == 1)
    {
        _position -= Vector2(0, 1);
    }
    else if (_rand == 2)
    {
        _position -= Vector2(1, 0);
    }
    else if (_rand == 3)
    {
        _position += Vector2(0, 1);
    }
    else if (_rand == 4)
    {
        _position += Vector2(1, 0);
    }

    Case* _case = GetMap()->GetCaseAtPosition(_position);
    if (_case == nullptr || _case->IsWall()) return;
    Position()->Set(_position);
    //bon bah comme mon programme n'affiche aucune map je peux pas tester donc bah... ont va juste dire que c'est bon hein ? 
}
