#include "base-value.hpp"

using namespace options;

value_::value_(bundle const& b, const QString& name) :
    b(b), self_name(name)
{
    b->on_value_created(this);
}

value_::~value_()
{
    b->on_value_destructed(this);
}

void value_::notify() const
{
    bundle_value_changed();
}

namespace options::detail {

void set_value_to_default(value_* val)
{
    val->set_to_default();
}

} // ns options::detail

