#ifndef ELFREADER_H
#define ELFREADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EL_NDIENT 16

#define SHN_UNDEF  0
#define SHN_LOPROC 0xFF00
#define SHN_HIPROC 0xFF1F
#define SHN_LOOS   0xFF20
#define SHN_HIOS   0xFF3F
#define SHN_ABS    0xFFF1
#define SHN_COMMON 0xFFF2

typedef unsigned int   Elf32_Addr;
typedef unsigned short Elf32_Half;
typedef unsigned int   Elf32_Offset;
typedef int            Elf32_SWord;
typedef unsigned int   Elf32_Word;
typedef unsigned char  Elf32_Char;

typedef unsigned long  Elf64_Addr;
typedef unsigned short Elf64_Half;
typedef unsigned long  Elf64_Offset;
typedef int            Elf64_SWord;
typedef unsigned int   Elf64_Word;
typedef unsigned long  Elf64_XWord;
typedef long           Elf64_SXWord;
typedef unsigned char  Elf64_Char;

typedef struct ELF32Header
{
    Elf32_Char   e_ident[EL_NDIENT];
    Elf32_Half   e_type;
    Elf32_Half   e_machine;
    Elf32_Word   e_version;
    Elf32_Addr   e_entry;
    Elf32_Offset e_poff;
    Elf32_Offset e_soff;
    Elf32_Word   e_flags;
    Elf32_Half   e_ehsize;
    Elf32_Half   e_phentsize;
    Elf32_Half   e_phnum;
    Elf32_Half   e_shentsize;
    Elf32_Half   e_shnum;
    Elf32_Half   e_shstrndx;
}Elf32_Ehdr;

typedef struct ELF64Header
{
    Elf64_Char   e_ident[EL_NDIENT];
    Elf64_Half   e_type;
    Elf64_Half   e_machine;
    Elf64_Word   e_version;
    Elf64_Addr   e_entry;
    Elf64_Offset e_poff;
    Elf64_Offset e_soff;
    Elf64_Word   e_flags;
    Elf64_Half   e_ehsize;
    Elf64_Half   e_phentsize;
    Elf64_Half   e_phnum;
    Elf64_Half   e_shentsize;
    Elf64_Half   e_shnum;
    Elf64_Half   e_shstrndx;
}Elf64_Ehdr;

typedef struct ELF64SectionHeader
{
    Elf64_Word   sh_name;      //Section name
    Elf64_Word   sh_type;      //Section type
    Elf64_XWord  sh_flags;     //Section attributes
    Elf64_Addr   sh_addr;      //Virtual address in memory
    Elf64_Offset sh_offset;    //Offset in file
    Elf64_XWord  sh_size;      //Size of section
    Elf64_Word   sh_link;      //Link to other section
    Elf64_Word   sh_info;      //Miscellaneous information
    Elf64_XWord  sh_addralign; //Adress alignment boundary
    Elf64_XWord  sh_entsize;   //Size of entries, if section has table

}Elf64_Shdr;

//1--elf32
//2--elf64
//3--unknown
int judgeType(FILE* fp);

//1--little
//2--big
//3--unknown
int judgeEnding(FILE* fp);

Elf64_Ehdr readHeader(FILE* fp);

Elf64_Shdr* readSectionHeader(FILE* fp, Elf64_Offset offset, Elf64_Half num);

#endif