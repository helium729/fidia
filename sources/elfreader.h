#ifndef ELFREADER_H
#define ELFREADER_H

#include <stdio.h>
#include <stdlib.h>

#define EL_NDIENT 16

typedef unsigned int Elf32_Addr;
typedef unsigned short Elf32_Half;
typedef unsigned int Elf32_Offset;
typedef int Elf32_SWord;
typedef unsigned int Elf32_Word;
typedef unsigned char Elf32_Char;

typedef struct ELF32Header
{
    Elf32_Char e_ident[EL_NDIENT];
    Elf32_Half e_type;
    Elf32_Half e_machine;
    Elf32_Word e_version;
    Elf32_Addr e_entry;
    Elf32_Offset e_poff;
    Elf32_Offset e_soff;
    Elf32_Word e_flags;
    Elf32_Half e_ehsize;
    Elf32_Half e_phentsize;
    Elf32_Half e_phnum;
    Elf32_Half e_shentsize;
    Elf32_Half e_shnum;
    Elf32_Half e_shstrndx;
}Elf32_Ehdr;

#endif