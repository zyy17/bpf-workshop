#include <stdlib.h>
#include <stdio.h>

#include "bpf/libbpf.h"
#include "bpf/bpf.h"

int main(void) {
    struct bpf_map_create_opts opts = {
            .sz = sizeof(struct bpf_map_create_opts),
    };

    int result;
    result = bpf_map_create(BPF_MAP_TYPE_HASH, "hello", 10, 10, 10, &opts);
    if (result < 0) {
        printf("error: %d\n", result);
        exit(1);
    }

    result = bpf_obj_pin(result, "/sys/fs/bpf/hello");
    if (result < 0) {
        printf("error: %d\n", result);
        exit(1);
    }

    while (1);
}