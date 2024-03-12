#pragma once

#include "TreeNode.hh"

#include <string>

namespace mana {
    class DivOp : public TreeNode {
    public:
        static constexpr ASTKind kind { ASTKind::kSlash };

        DivOp(std::unique_ptr<TreeNode> lhs, std::unique_ptr<TreeNode> rhs);

        std::unique_ptr<TreeNode> clone() override;

        void print(std::ostream& stream, size_t ident) override;
    private:
        std::unique_ptr<TreeNode> m_lhs;
        std::unique_ptr<TreeNode> m_rhs;
    };
}