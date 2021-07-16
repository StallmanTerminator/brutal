#include <brutal/base.h>
#include <brutal/log.h>
#include <handover/handover.h>

HandoverModule *handover_find_module(Handover *handover, Str name)
{
    for (size_t i = 0; i < handover->modules.module_count; i++)
    {
        if (str_eq(name, str_cast(&handover->modules.module[i].module_name)))
        {
            return &handover->modules.module[i];
        }
    }

    return nullptr;
}