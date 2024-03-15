#pragma once

#include "TreeNode.hh"
#include "Declaration.hh"

#include <filesystem>

namespace mana::ast {
    class ImportDecl : public Declaration {
    public:
        ImportDecl(
            std::vector<std::filesystem::path> pathlist,
            bool is_cc = false
        );

        std::unique_ptr<TreeNode> clone() override;

        void print(std::ostream& stream, size_t ident) override;

        void accept(TreeVisitor* visitor) override;
    private:
        std::vector<std::filesystem::path> m_pathlist;
        bool m_isCc;
    };
}