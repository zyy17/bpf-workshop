#include "vmlinux.h"

#include "bpf/bpf_helpers.h"
#include "bpf/bpf_tracing.h"

char LICENSE[] SEC("license") = "Dual BSD/GPL";

struct foo {
    u32 key;
};

struct bar {
    u32 value;
};

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 8192);
    __type(key, struct foo);
    __type(value, struct bar);
} example_map SEC(".maps");

SEC("tp/sched/sched_process_exec")
int handle_exec(struct trace_event_raw_sched_process_exec *ctx) {
    bpf_printk("trigger sched_process_exec\n");
    return 0;
}
