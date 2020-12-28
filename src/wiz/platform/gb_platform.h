#ifndef WIZ_PLATFORM_GB_H
#define WIZ_PLATFORM_GB_H

#include <wiz/platform/platform.h>

namespace wiz {
    class GameBoyPlatform : public Platform {
        public:
            GameBoyPlatform();
            ~GameBoyPlatform() override;

            void reserveDefinitions(Builtins& builtins) override;
            Definition* getPointerSizedType() const override;
            Definition* getFarPointerSizedType() const override;
            std::unique_ptr<PlatformTestAndBranch> getTestAndBranch(const Compiler& compiler, const Definition* type, BinaryOperatorKind op, const Expression* left, const Expression* right, std::size_t distanceHint) const override;
            Definition* getZeroFlag() const override;
            Int128 getPlaceholderValue() const override;

        private:
            FwdUniquePtr<Expression> bitIndex7Expression;

            Definition* pointerSizedType = nullptr;
            Definition* farPointerSizedType = nullptr;

            Definition* a = nullptr;
            Definition* zero = nullptr;
            Definition* carry = nullptr;
            Definition* cmp = nullptr;
            Definition* bit = nullptr;
    };
}

#endif
