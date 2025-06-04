
        .globl  mul3
        
        .text
mul3:
        imulq %rsi, %rdi      # rdi = rdi * rsi   (a * b)
        imulq %rdx, %rdi      # rdi = rdi * rdx  (a * b * c)
        movq  %rdi, %rax      # 返回值存入 rax
        ret                   # 返回呼叫者

