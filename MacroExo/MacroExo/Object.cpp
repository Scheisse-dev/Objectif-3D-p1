#include "Object.h"





bool Object::IsInterface() const
{
    return bitMask & Interface;
}

bool Object::IsClass() const
{
    return !(bitMask & Interface);
}

bool Object::IsAbstract() const
{
    return bitMask & Abstract;
}

int Object::SetBitMask(int _mask)
{
    return bitMask = _mask;
}
