#include "FixComponent.h"
#include "Felix.h"


FixComponent::FixComponent(Felix* owner,
    int updateOrder)
    :Component(owner, updateOrder)
{
    
}

FixComponent::~FixComponent() 
{

}

void FixComponent::Update(float deltaTime)
{

}
     
void FixComponent::Fix(BrokenSpriteComponent* window)
{
    window->Fix();
}
