#include "GridComponent.h"
#include "Window.h"
#include "Floor.h"

template class GridComponent<Floor>;
template class GridComponent<Window>;

template <class G>
GridComponent<G>::GridComponent(Actor* owner, int e, 
    float xP, float yP, float sp,
    bool isH, 
    int updateOrder)
    :Component(owner, updateOrder), 
    numElements(e), 
    isHorizontal(isH)
{
    //Grid.resize(numElements);
    width = owner->GetWidth();
    height = owner->GetHeight();

    xPadding = xP * width;
    yPadding = yP * height;
    spacing = sp * (isH ? width : height);

    width -= 2 * xPadding;
    height -= 2 * yPadding;

    Vector2 ownerPos = owner->GetPosition();
    xOwner = ownerPos.x;
    yOwner = ownerPos.y;

    FillGrid();
}

template <class G>
void GridComponent<G>::FillGrid()
{
    Game* game = mOwner->GetGame();

    if (isHorizontal) {
        float wElement = (width - spacing * (numElements - 1) ) / numElements;
        float hElement = height;
        float yElement = yOwner;
        float firstX = xOwner - width / 2 + wElement / 2;

        for (int i = 0; i < numElements; i++) {
            float xElement = firstX + i * (spacing + wElement);
            G* mElement = new G(game, xElement, yElement, wElement, hElement);
        }
    }

    // vertical
    else{
        float wElement = width;
        float hElement = (height - spacing * (numElements - 1) ) / numElements;
        float xElement = xOwner;
        float firstY = yOwner - height/ 2 + hElement / 2;

        for (int i = 0; i < numElements; i++) {
            float yElement = firstY + i * (spacing + hElement);
            G* mElement = new G(game, xElement, yElement, wElement, hElement);
        }
    }
}