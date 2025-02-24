#pragma once

#include "torch_xla/csrc/ir.h"

namespace torch_xla {
namespace ir {
namespace ops {

class Linspace : public Node {
 public:
  Linspace(const Value& start, const Value& end, const int64_t steps);

  std::string ToString() const override;

  NodePtr Clone(OpList operands) const override;

  XlaOpVector Lower(LoweringContext* loctx) const override;

  int64_t steps() const { return steps_; };

 private:
  int64_t steps_;
};

}  // namespace ops
}  // namespace ir
}  // namespace torch_xla
