#include "../lib/console.h"
#include "../h/syscall_cpp.h"
#include "../test/printing.hpp"
#include "../h/riscv.h"
#include "../h/tcb.h"

#include "../h/syscall_c.h"
#include "../h/myConsole.h"

void userMain();
void consoleConsumerBody();
void idleThreadBody();

TCB* idle;
TCB* Main;
int main(){
    Riscv::w_stvec((uint64) &Riscv::supervisorTrap);
    MemoryAllocator::init();

    Main = TCB::createThread(nullptr, nullptr, nullptr,false);
    TCB::running = Main;
    myConsole::console_init();

    TCB::createThread(reinterpret_cast<void (*)(void *)>(consoleConsumerBody),
                                   static_cast<uint64 *>(mem_alloc(2 * (DEFAULT_STACK_SIZE))), nullptr,true);

    idle = TCB::createThread(reinterpret_cast<void (*)(void *)>(idleThreadBody),
                             static_cast<uint64 *>(mem_alloc(2 * (DEFAULT_STACK_SIZE))), nullptr,false);

    // Enable Console interrupt
    Riscv::ms_sie(Riscv::SIE_SEIE);
    Riscv::ms_sstatus(Riscv::SSTATUS_SIE);

    thread_t userMainThread;
    thread_create(&userMainThread, reinterpret_cast<void (*)(void *)>(userMain), nullptr);
    while (!userMainThread->isFinished())
        thread_dispatch();


    thread_dispatch();   // Empty output buffer one last time

    return 0;
}