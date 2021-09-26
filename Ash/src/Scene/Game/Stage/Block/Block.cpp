#include "Block.hpp"

namespace Ash
{
    Block::Block(const RectF& rect)
        : m_rect(rect)
    {
    }


    void Block::draw() const
    {
    }


    bool Block::intersects(const RectF& another)
    {
        return Abs(m_rect.center().y - another.y) < (m_rect.h + another.h) / 2 && Abs(m_rect.center().x - another.x) < (m_rect.w + another.w) / 2;
    }
}
