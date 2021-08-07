#include <bs/bs.h>

void bs_dump(BsExpr const *expr, IoWriter *writer)
{
    print(writer, "{}[", bs_type_to_string(expr->type));

    switch (expr->type)
    {
    case BS_NIL:
        break;

    case BS_BOOL:
        print(writer, expr->bool_ ? "true" : "false");
        break;

    case BS_ATOM:
        print(writer, "{}", expr->atom_);
        break;

    case BS_NUM:
        print(writer, "{}", expr->num_);
        break;

    case BS_RUNE:
        if (isprint(expr->rune_))
        {
            print(writer, "{c}", expr->rune_);
        }
        else
        {
            print(writer, "{#02x}", expr->rune_);
        }
        break;

    case BS_PAIR:
        print(writer, "lhs=");
        bs_dump(expr->pair_.lhs, writer);
        print(writer, ", rhs=");
        bs_dump(expr->pair_.rhs, writer);
        break;

    case BS_LAMBDA:
        print(writer, "params=");
        bs_dump(expr->lambda_.parms, writer);
        print(writer, ", env=");
        bs_dump(expr->lambda_.env, writer);
        print(writer, ", body=");
        bs_dump(expr->lambda_.body, writer);

    default:
        break;
    }

    print(writer, "]", bs_type_to_string(expr->type));
}
