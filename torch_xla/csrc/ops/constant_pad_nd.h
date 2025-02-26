#pragma once

#include <c10/core/Scalar.h>

#include "torch_xla/csrc/ir.h"

namespace torch_xla {
namespace ir {
namespace ops {

class ConstantPadNd : public Node {
 public:
  ConstantPadNd(const Value& input, std::vector<int64_t> pad,
                const at::Scalar& value);

  std::string ToString() const override;

  NodePtr Clone(OpList operands) const override;

  XlaOpVector Lower(LoweringContext* loctx) const override;

  const at::Scalar& value() const { return value_; }

  const std::vector<int64_t>& pad() const { return pad_; }

 private:
  std::vector<int64_t> pad_;
  at::Scalar value_;
};

}  // namespace ops
}  // namespace ir
}  // namespace torch_xla
