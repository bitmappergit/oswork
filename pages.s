[GLOBAL load_page_directory]

load_page_directory:
  push ebp
  mov ebp, esp
  mov [esp+8], eax
  mov cr3, eax
  mov esp, ebp
  pop ebp
  ret

[GLOBAL enable_paging]

enable_paging:
  push ebp
  mov ebp, esp
  mov eax, cr0
  or eax, 0x8000000
  mov cr0, eax
  mov esp, ebp
  pop ebp
  ret
