#pragma once

#include "BinaryOp.hh"

#include <string>

namespace mana {
    class SumOp : public BinaryOp {
    public:
        static constexpr BinaryOp::TypeMask::Enum kind { BinaryOp::TypeMask::kSum };

        SumOp(std::unique_ptr<TreeNode> lhs, std::unique_ptr<TreeNode> rhs);

        std::unique_ptr<TreeNode> clone() override;

        void print(std::ostream& stream, size_t ident) override;

        void accept(TreeVisitor* visitor) override;
    };
}