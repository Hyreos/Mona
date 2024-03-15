#include "DivOp.hh"

#include "TreeTransverser.hh"

namespace mana::ast {
    DivOp::DivOp(std::unique_ptr<TreeNode> lhs, std::unique_ptr<TreeNode> rhs)
        : BinaryOp(kind, std::move(lhs), std::move(rhs))
    {
    }

    std::unique_ptr<TreeNode> DivOp::clone()
    {
        return std::make_unique<DivOp>(m_lhs->clone(), m_rhs->clone());
    }

    void DivOp::print(std::ostream& stream, size_t ident)
    {
        TreeNode::print(stream, ident);

        stream << "(";

        m_lhs->print(stream, ident);

        stream << " / ";

        m_rhs->print(stream, ident);

        stream << ")";
    }

    void DivOp::accept(TreeVisitor* visitor)
    {
        visitor->visit(this);
    }
}