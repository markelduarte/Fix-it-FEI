#pragma once

#include "BrokenSpriteComponent.h"
#include "Component.h"

class FixComponent :
    public Component
{
public:
    FixComponent(class Felix* owner,
        int updateOrder = 100);
    ~FixComponent();

    void Update(float deltaTime) override;

    void Fix(BrokenSpriteComponent* window);

private:


};

