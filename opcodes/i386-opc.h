/* Declarations for Intel 80386 opcode table
   Copyright 2007, 2008, 2009
   Free Software Foundation, Inc.

   This file is part of the GNU opcodes library.

   This library is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with GAS; see the file COPYING.  If not, write to the Free
   Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA
   02110-1301, USA.  */

#include "opcode/i386.h"
#ifdef HAVE_LIMITS_H
#include <limits.h>
#endif

#ifndef CHAR_BIT
#define CHAR_BIT 8
#endif

/* Position of cpu flags bitfiled.  */

enum
{
  /* i186 or better required */
  Cpu186 = 0,
  /* i286 or better required */
  Cpu286,
  /* i386 or better required */
  Cpu386,
  /* i486 or better required */
  Cpu486,
  /* i585 or better required */
  Cpu586,
  /* i686 or better required */
  Cpu686,
  /* CLFLUSH Instuction support required */
  CpuClflush,
  /* SYSCALL Instuctions support required */
  CpuSYSCALL,
  /* Floating point support required */
  Cpu8087,
  /* i287 support required */
  Cpu287,
  /* i387 support required */
  Cpu387,
  /* i686 and floating point support required */
  Cpu687,
  /* SSE3 and floating point support required */
  CpuFISTTP,
  /* MMX support required */
  CpuMMX,
  /* SSE support required */
  CpuSSE,
  /* SSE2 support required */
  CpuSSE2,
  /* 3dnow! support required */
  Cpu3dnow,
  /* 3dnow! Extensions support required */
  Cpu3dnowA,
  /* SSE3 support required */
  CpuSSE3,
  /* VIA PadLock required */
  CpuPadLock,
  /* AMD Secure Virtual Machine Ext-s required */
  CpuSVME,
  /* VMX Instructions required */
  CpuVMX,
  /* SMX Instructions required */
  CpuSMX,
  /* SSSE3 support required */
  CpuSSSE3,
  /* SSE4a support required */
  CpuSSE4a,
  /* ABM New Instructions required */
  CpuABM,
  /* SSE4.1 support required */
  CpuSSE4_1,
  /* SSE4.2 support required */
  CpuSSE4_2,
  /* AVX support required */
  CpuAVX,
  /* Intel L1OM support required */
  CpuL1OM,
  /* Xsave/xrstor New Instuctions support required */
  CpuXsave,
  /* AES support required */
  CpuAES,
  /* PCLMUL support required */
  CpuPCLMUL,
  /* FMA support required */
  CpuFMA,
  /* FMA4 support required */
  CpuFMA4,
  /* XOP support required */
  CpuXOP,
  /* CVT16 support required */
  CpuCVT16,
  /* LWP support required */
  CpuLWP,
  /* MOVBE Instuction support required */
  CpuMovbe,
  /* EPT Instructions required */
  CpuEPT,
  /* RDTSCP Instuction support required */
  CpuRdtscp,
  /* 64bit support available, used by -march= in assembler.  */
  CpuLM,
  /* 64bit support required  */
  Cpu64,
  /* Not supported in the 64bit mode  */
  CpuNo64,
  /* The last bitfield in i386_cpu_flags.  */
  CpuMax = CpuNo64
};

#define CpuNumOfUints \
  (CpuMax / sizeof (unsigned int) / CHAR_BIT + 1)
#define CpuNumOfBits \
  (CpuNumOfUints * sizeof (unsigned int) * CHAR_BIT)

/* If you get a compiler error for zero width of the unused field,
   comment it out.  */
#define CpuUnused	(CpuMax + 1)

/* We can check if an instruction is available with array instead
   of bitfield. */
typedef union i386_cpu_flags
{
  struct
    {
      unsigned int cpui186:1;
      unsigned int cpui286:1;
      unsigned int cpui386:1;
      unsigned int cpui486:1;
      unsigned int cpui586:1;
      unsigned int cpui686:1;
      unsigned int cpuclflush:1;
      unsigned int cpusyscall:1;
      unsigned int cpu8087:1;
      unsigned int cpu287:1;
      unsigned int cpu387:1;
      unsigned int cpu687:1;
      unsigned int cpufisttp:1;
      unsigned int cpummx:1;
      unsigned int cpusse:1;
      unsigned int cpusse2:1;
      unsigned int cpua3dnow:1;
      unsigned int cpua3dnowa:1;
      unsigned int cpusse3:1;
      unsigned int cpupadlock:1;
      unsigned int cpusvme:1;
      unsigned int cpuvmx:1;
      unsigned int cpusmx:1;
      unsigned int cpussse3:1;
      unsigned int cpusse4a:1;
      unsigned int cpuabm:1;
      unsigned int cpusse4_1:1;
      unsigned int cpusse4_2:1;
      unsigned int cpuavx:1;
      unsigned int cpul1om:1;
      unsigned int cpuxsave:1;
      unsigned int cpuaes:1;
      unsigned int cpupclmul:1;
      unsigned int cpufma:1;
      unsigned int cpufma4:1;
      unsigned int cpuxop:1;
      unsigned int cpucvt16:1;
      unsigned int cpulwp:1;
      unsigned int cpumovbe:1;
      unsigned int cpuept:1;
      unsigned int cpurdtscp:1;
      unsigned int cpulm:1;
      unsigned int cpu64:1;
      unsigned int cpuno64:1;
#ifdef CpuUnused
      unsigned int unused:(CpuNumOfBits - CpuUnused);
#endif
    } bitfield;
  unsigned int array[CpuNumOfUints];
} i386_cpu_flags;

/* Position of opcode_modifier bits.  */

enum
{
  /* has direction bit. */
  D = 0,
  /* set if operands can be words or dwords encoded the canonical way */
  W,
  /* Skip the current insn and use the next insn in i386-opc.tbl to swap
     operand in encoding.  */
  S,
  /* insn has a modrm byte. */
  Modrm,
  /* register is in low 3 bits of opcode */
  ShortForm,
  /* special case for jump insns.  */
  Jump,
  /* call and jump */
  JumpDword,
  /* loop and jecxz */
  JumpByte,
  /* special case for intersegment leaps/calls */
  JumpInterSegment,
  /* FP insn memory format bit, sized by 0x4 */
  FloatMF,
  /* src/dest swap for floats. */
  FloatR,
  /* has float insn direction bit. */
  FloatD,
  /* needs size prefix if in 32-bit mode */
  Size16,
  /* needs size prefix if in 16-bit mode */
  Size32,
  /* needs size prefix if in 64-bit mode */
  Size64,
  /* instruction ignores operand size prefix and in Intel mode ignores
     mnemonic size suffix check.  */
  IgnoreSize,
  /* default insn size depends on mode */
  DefaultSize,
  /* b suffix on instruction illegal */
  No_bSuf,
  /* w suffix on instruction illegal */
  No_wSuf,
  /* l suffix on instruction illegal */
  No_lSuf,
  /* s suffix on instruction illegal */
  No_sSuf,
  /* q suffix on instruction illegal */
  No_qSuf,
  /* long double suffix on instruction illegal */
  No_ldSuf,
  /* instruction needs FWAIT */
  FWait,
  /* quick test for string instructions */
  IsString,
  /* quick test for lockable instructions */
  IsLockable,
  /* fake an extra reg operand for clr, imul and special register
     processing for some instructions.  */
  RegKludge,
  /* The first operand must be xmm0 */
  FirstXmm0,
  /* An implicit xmm0 as the first operand */
  Implicit1stXmm0,
  /* BYTE is OK in Intel syntax. */
  ByteOkIntel,
  /* Convert to DWORD */
  ToDword,
  /* Convert to QWORD */
  ToQword,
  /* Address prefix changes operand 0 */
  AddrPrefixOp0,
  /* opcode is a prefix */
  IsPrefix,
  /* instruction has extension in 8 bit imm */
  ImmExt,
  /* instruction don't need Rex64 prefix.  */
  NoRex64,
  /* instruction require Rex64 prefix.  */
  Rex64,
  /* deprecated fp insn, gets a warning */
  Ugh,
  /* insn has VEX prefix:
	1: 128bit VEX prefix.
	2: 256bit VEX prefix.
   */
  Vex,
  /* insn has VEX NDS. Register-only source is encoded in Vex prefix.
     We use VexNDS on insns with VEX DDS since the register-only source
     is the second source register.  */
  VexNDS,
  /* insn has VEX NDD. Register destination is encoded in Vex prefix. */
  VexNDD,
  /* insn has VEX NDD. Register destination is encoded in Vex prefix
     and one of the operands can access a memory location.  */
  VexLWP,
  /* insn has VEX W0. */
  VexW0,
  /* insn has VEX W1. */
  VexW1,
  /* insn has VEX 0x0F opcode prefix. */
  Vex0F,
  /* insn has VEX 0x0F38 opcode prefix. */
  Vex0F38,
  /* insn has VEX 0x0F3A opcode prefix. */
  Vex0F3A,
  /* insn has XOP 0x08 opcode prefix. */
  XOP08,
  /* insn has XOP 0x09 opcode prefix. */
  XOP09,
  /* insn has XOP 0x0A opcode prefix. */
  XOP0A,
  /* insn has VEX prefix with 2 sources. */
  Vex2Sources,
  /* insn has VEX prefix with 3 sources. */
  Vex3Sources,
  /* instruction has VEX 8 bit imm */
  VexImmExt,
  /* SSE to AVX support required */
  SSE2AVX,
  /* No AVX equivalent */
  NoAVX,
  /* Compatible with old (<= 2.8.1) versions of gcc  */
  OldGcc,
  /* AT&T mnemonic.  */
  ATTMnemonic,
  /* AT&T syntax.  */
  ATTSyntax,
  /* Intel syntax.  */
  IntelSyntax,
  /* The last bitfield in i386_opcode_modifier.  */
  Opcode_Modifier_Max
};

typedef struct i386_opcode_modifier
{
  unsigned int d:1;
  unsigned int w:1;
  unsigned int s:1;
  unsigned int modrm:1;
  unsigned int shortform:1;
  unsigned int jump:1;
  unsigned int jumpdword:1;
  unsigned int jumpbyte:1;
  unsigned int jumpintersegment:1;
  unsigned int floatmf:1;
  unsigned int floatr:1;
  unsigned int floatd:1;
  unsigned int size16:1;
  unsigned int size32:1;
  unsigned int size64:1;
  unsigned int ignoresize:1;
  unsigned int defaultsize:1;
  unsigned int no_bsuf:1;
  unsigned int no_wsuf:1;
  unsigned int no_lsuf:1;
  unsigned int no_ssuf:1;
  unsigned int no_qsuf:1;
  unsigned int no_ldsuf:1;
  unsigned int fwait:1;
  unsigned int isstring:1;
  unsigned int islockable:1;
  unsigned int regkludge:1;
  unsigned int firstxmm0:1;
  unsigned int implicit1stxmm0:1;
  unsigned int byteokintel:1;
  unsigned int todword:1;
  unsigned int toqword:1;
  unsigned int addrprefixop0:1;
  unsigned int isprefix:1;
  unsigned int immext:1;
  unsigned int norex64:1;
  unsigned int rex64:1;
  unsigned int ugh:1;
  unsigned int vex:2;
  unsigned int vexnds:1;
  unsigned int vexndd:1;
  unsigned int vexlwp:1;
  unsigned int vexw0:1;
  unsigned int vexw1:1;
  unsigned int vex0f:1;
  unsigned int vex0f38:1;
  unsigned int vex0f3a:1;
  unsigned int xop08:1;
  unsigned int xop09:1;
  unsigned int xop0a:1;
  unsigned int vex2sources:1;
  unsigned int vex3sources:1;
  unsigned int veximmext:1;
  unsigned int sse2avx:1;
  unsigned int noavx:1;
  unsigned int oldgcc:1;
  unsigned int attmnemonic:1;
  unsigned int attsyntax:1;
  unsigned int intelsyntax:1;
} i386_opcode_modifier;

/* Position of operand_type bits.  */

enum
{
  /* 8bit register */
  Reg8 = 0,
  /* 16bit register */
  Reg16,
  /* 32bit register */
  Reg32,
  /* 64bit register */
  Reg64,
  /* Floating pointer stack register */
  FloatReg,
  /* MMX register */
  RegMMX,
  /* SSE register */
  RegXMM,
  /* AVX registers */
  RegYMM,
  /* Control register */
  Control,
  /* Debug register */
  Debug,
  /* Test register */
  Test,
  /* 2 bit segment register */
  SReg2,
  /* 3 bit segment register */
  SReg3,
  /* 1 bit immediate */
  Imm1,
  /* 8 bit immediate */
  Imm8,
  /* 8 bit immediate sign extended */
  Imm8S,
  /* 16 bit immediate */
  Imm16,
  /* 32 bit immediate */
  Imm32,
  /* 32 bit immediate sign extended */
  Imm32S,
  /* 64 bit immediate */
  Imm64,
  /* 8bit/16bit/32bit displacements are used in different ways,
     depending on the instruction.  For jumps, they specify the
     size of the PC relative displacement, for instructions with
     memory operand, they specify the size of the offset relative
     to the base register, and for instructions with memory offset
     such as `mov 1234,%al' they specify the size of the offset
     relative to the segment base.  */
  /* 8 bit displacement */
  Disp8,
  /* 16 bit displacement */
  Disp16,
  /* 32 bit displacement */
  Disp32,
  /* 32 bit signed displacement */
  Disp32S,
  /* 64 bit displacement */
  Disp64,
  /* Accumulator %al/%ax/%eax/%rax */
  Acc,
  /* Floating pointer top stack register %st(0) */
  FloatAcc,
  /* Register which can be used for base or index in memory operand.  */
  BaseIndex,
  /* Register to hold in/out port addr = dx */
  InOutPortReg,
  /* Register to hold shift count = cl */
  ShiftCount,
  /* Absolute address for jump.  */
  JumpAbsolute,
  /* String insn operand with fixed es segment */
  EsSeg,
  /* RegMem is for instructions with a modrm byte where the register
     destination operand should be encoded in the mod and regmem fields.
     Normally, it will be encoded in the reg field. We add a RegMem
     flag to the destination register operand to indicate that it should
     be encoded in the regmem field.  */
  RegMem,
  /* Memory.  */
  Mem,
  /* BYTE memory. */
  Byte,
  /* WORD memory. 2 byte */
  Word,
  /* DWORD memory. 4 byte */
  Dword,
  /* FWORD memory. 6 byte */
  Fword,
  /* QWORD memory. 8 byte */
  Qword,
  /* TBYTE memory. 10 byte */
  Tbyte,
  /* XMMWORD memory. */
  Xmmword,
  /* YMMWORD memory. */
  Ymmword,
  /* Unspecified memory size.  */
  Unspecified,
  /* Any memory size.  */
  Anysize,

  /* The last bitfield in i386_operand_type.  */
  OTMax
};

#define OTNumOfUints \
  (OTMax / sizeof (unsigned int) / CHAR_BIT + 1)
#define OTNumOfBits \
  (OTNumOfUints * sizeof (unsigned int) * CHAR_BIT)

/* If you get a compiler error for zero width of the unused field,
   comment it out.  */
#define OTUnused		(OTMax + 1)

typedef union i386_operand_type
{
  struct
    {
      unsigned int reg8:1;
      unsigned int reg16:1;
      unsigned int reg32:1;
      unsigned int reg64:1;
      unsigned int floatreg:1;
      unsigned int regmmx:1;
      unsigned int regxmm:1;
      unsigned int regymm:1;
      unsigned int control:1;
      unsigned int debug:1;
      unsigned int test:1;
      unsigned int sreg2:1;
      unsigned int sreg3:1;
      unsigned int imm1:1;
      unsigned int imm8:1;
      unsigned int imm8s:1;
      unsigned int imm16:1;
      unsigned int imm32:1;
      unsigned int imm32s:1;
      unsigned int imm64:1;
      unsigned int disp8:1;
      unsigned int disp16:1;
      unsigned int disp32:1;
      unsigned int disp32s:1;
      unsigned int disp64:1;
      unsigned int acc:1;
      unsigned int floatacc:1;
      unsigned int baseindex:1;
      unsigned int inoutportreg:1;
      unsigned int shiftcount:1;
      unsigned int jumpabsolute:1;
      unsigned int esseg:1;
      unsigned int regmem:1;
      unsigned int mem:1;
      unsigned int byte:1;
      unsigned int word:1;
      unsigned int dword:1;
      unsigned int fword:1;
      unsigned int qword:1;
      unsigned int tbyte:1;
      unsigned int xmmword:1;
      unsigned int ymmword:1;
      unsigned int unspecified:1;
      unsigned int anysize:1;
#ifdef OTUnused
      unsigned int unused:(OTNumOfBits - OTUnused);
#endif
    } bitfield;
  unsigned int array[OTNumOfUints];
} i386_operand_type;

typedef struct insn_template
{
  /* instruction name sans width suffix ("mov" for movl insns) */
  char *name;

  /* how many operands */
  unsigned int operands;

  /* base_opcode is the fundamental opcode byte without optional
     prefix(es).  */
  unsigned int base_opcode;
#define Opcode_D	0x2 /* Direction bit:
			       set if Reg --> Regmem;
			       unset if Regmem --> Reg. */
#define Opcode_FloatR	0x8 /* Bit to swap src/dest for float insns. */
#define Opcode_FloatD 0x400 /* Direction bit for float insns. */

  /* extension_opcode is the 3 bit extension for group <n> insns.
     This field is also used to store the 8-bit opcode suffix for the
     AMD 3DNow! instructions.
     If this template has no extension opcode (the usual case) use None 
     Instructions */
  unsigned int extension_opcode;
#define None 0xffff		/* If no extension_opcode is possible.  */

  /* Opcode length.  */
  unsigned char opcode_length;

  /* cpu feature flags */
  i386_cpu_flags cpu_flags;

  /* the bits in opcode_modifier are used to generate the final opcode from
     the base_opcode.  These bits also are used to detect alternate forms of
     the same instruction */
  i386_opcode_modifier opcode_modifier;

  /* operand_types[i] describes the type of operand i.  This is made
     by OR'ing together all of the possible type masks.  (e.g.
     'operand_types[i] = Reg|Imm' specifies that operand i can be
     either a register or an immediate operand.  */
  i386_operand_type operand_types[MAX_OPERANDS];
}
insn_template;

extern const insn_template i386_optab[];

/* these are for register name --> number & type hash lookup */
typedef struct
{
  char *reg_name;
  i386_operand_type reg_type;
  unsigned char reg_flags;
#define RegRex	    0x1  /* Extended register.  */
#define RegRex64    0x2  /* Extended 8 bit register.  */
  unsigned char reg_num;
#define RegRip	((unsigned char ) ~0)
#define RegEip	(RegRip - 1)
/* EIZ and RIZ are fake index registers.  */
#define RegEiz	(RegEip - 1)
#define RegRiz	(RegEiz - 1)
/* FLAT is a fake segment register (Intel mode).  */
#define RegFlat     ((unsigned char) ~0)
  signed char dw2_regnum[2];
#define Dw2Inval (-1)
}
reg_entry;

/* Entries in i386_regtab.  */
#define REGNAM_AL 1
#define REGNAM_AX 25
#define REGNAM_EAX 41

extern const reg_entry i386_regtab[];
extern const unsigned int i386_regtab_size;

typedef struct
{
  char *seg_name;
  unsigned int seg_prefix;
}
seg_entry;

extern const seg_entry cs;
extern const seg_entry ds;
extern const seg_entry ss;
extern const seg_entry es;
extern const seg_entry fs;
extern const seg_entry gs;
