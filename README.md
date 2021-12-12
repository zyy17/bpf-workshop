# bpf-workshp

bpf-workshop is just the simplest skeleton that helps developers to write their bpf codes. It only contains the `example.bpf.c`.

## How to Build

```
$ make
```

Then `example.bpf.c` will be compiled into `example.bpf.o`.

You can use `make clean` to delete `*.bpf.o`.

## libbpf and vmlinux.h

- `include/bpf`

  - From [libbpf v0.6.1](https://github.com/libbpf/libbpf/releases/tag/v0.6.1) release version
  - Build from the following commands:
    ```shell
    $ cd src/
    $ mkdir build root
    $ BUILD_STATIC_ONLY=y OBJDIR=build DESTDIR=root make install
    ```
    Then copy `root/usr/include/bpf` directory.

- `include/vmlinux.h`: It's the symbol link of `bpf/include/vmlinux_510.h` and dump from linux 5.10 kernel:

   ```shell
   $ bpftool btf dump file /sys/kernel/btf/vmlinux format c
   ```

## Code Style

- Use `.clang-format` to format C codes: The clang format is from linux kernel(linux-5.13.12) and use spaces instead of tab.