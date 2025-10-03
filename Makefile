################################################################################
# Ben Baker 2020
# zxnext_layer2_tilemap
################################################################################

M4 := m4

MKDIR := mkdir -p

RM := rm -rf

CP := cp

ZIP := zip -r -q

BINDIR := bin

CFG := config/zconfig.h config/zconfig.def config/zpragma.inc config/zconfig.m4 zproject.lst

DEBUGFLAGS := --list --c-code-in-asm

BUILD_OPT := false

ifeq ($(BUILD_OPT), true)
CFLAGS_OPT := -SO3 --max-allocs-per-node200000
endif

# sdcc_ix, sdcc_iy, new

CFLAGS := +zxn -subtype=nex -vn -startup=31 -clib=sdcc_iy -m $(CFLAGS_OPT)

all: CFG
	$(MKDIR) $(BINDIR)
	zcc $(CFLAGS) $(DEBUG) -pragma-include:config/zpragma.inc @zproject.lst -o $(BINDIR)/zxnext_layer2_tilemap -Cz"--main-fence 0xBE80" -create-app

debug: DEBUG = $(DEBUGFLAGS)

debug: all

CFG: $(CFG)

config/zconfig.h: config/configure.m4
	$(M4) -DTARGET=1 $(CONFIG) $< > $@

config/zconfig.def: config/configure.m4
	$(M4) -DTARGET=2 $(CONFIG) $< > $@

config/zconfig.m4: config/configure.m4
	$(M4) -DTARGET=3 $(CONFIG) $< > $@

config/zpragma.inc: config/configure.m4
	$(M4) -DTARGET=4 $(CONFIG) $< > $@

zproject.lst: config/configure.m4
	$(M4) -DTARGET=5 $(CONFIG) $< > $@

clean:
	$(RM) bin tmp zcc_opt.def zcc_proj.lst src/*.lis
