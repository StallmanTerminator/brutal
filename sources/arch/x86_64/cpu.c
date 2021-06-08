#include "arch/cpu.h"

#include "arch/x86_64/apic.h"
#include "arch/x86_64/cpu.h"
#include "kernel/cpu.h"

static struct cpu_context cpu_context_array[MAX_CPU_COUNT];

struct cpu_context *cpu_context_this(void)
{
    return &cpu_context_array[arch_cpu_current_id()];
}

struct cpu_context *cpu_context(cpu_id_t id)
{
    return &cpu_context_array[id];
}

void cpu_context_found(cpu_id_t id, int lapic)
{
    cpu_found(id);
    cpu_context(id)->lapic = lapic;
}

/* --- Public API ----------------------------------------------------------- */

cpu_id_t arch_cpu_current_id(void)
{
    return apic_current_cpu();
}

struct cpu *arch_cpu_this(void)
{
    return &cpu_context_this()->base;
}

struct cpu *arch_cpu(cpu_id_t id)
{
    return &cpu_context(id)->base;
}