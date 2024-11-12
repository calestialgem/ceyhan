#include <Windows.h>
#include <stdint.h>

[[noreturn]]
void sakarya_windows_ExitProcess(uint32_t code) {
    ExitProcess(code);
}
