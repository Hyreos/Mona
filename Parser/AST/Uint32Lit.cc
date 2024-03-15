#include "Uint32Lit.hh"

#include "TreeTransverser.hh"

namespace mana::ast {
    Uint32Lit::Uint32Lit(uint32_t value) 
        : Literal(value),
            m_value { value }
    {
    }

    std::unique_ptr<TreeNode> Uint32Lit::clone()
    {
        return std::make_unique<Uint32Lit>(m_value);
    }

    void Uint32Lit::print(std::ostream& stream, size_t ident)
    {
        TreeNode::print(stream, ident);

        stream << "(" << m_value << "_u32" << ")";
    }

    void Uint32Lit::accept(TreeVisitor* visitor)
    {
        visitor->visit(static_cast<Literal*>(this));
    }
}