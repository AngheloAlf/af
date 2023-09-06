WARNINGS_CHECK ?= 0

UNAME_S := $(shell uname -s)
ifeq ($(OS),Windows_NT)
	DETECTED_OS := windows
	DOWNLOAD_OS := windows-latest
else ifeq ($(UNAME_S),Linux)
	DETECTED_OS := linux
	DOWNLOAD_OS := ubuntu-20.04
else ifeq ($(UNAME_S),Darwin)
	DETECTED_OS := macos
	DOWNLOAD_OS := macos-latest
endif


WGET_FLAGS  ?=
ifneq ($(WARNINGS_CHECK), 0)
    WGET_FLAGS += --quiet
endif



IDO_5_3_DIR     := ido/$(DETECTED_OS)/5.3
IDO_5_3         := $(IDO_5_3_DIR)/cc

IDO_7_1_DIR     := ido/$(DETECTED_OS)/7.1
IDO_7_1         := $(IDO_7_1_DIR)/cc

EGCS_DIR        := gcc_egcs/$(DETECTED_OS)/1.1.2-4
EGCS_GCC        := $(EGCS_DIR)/gcc
EGCS_BINUTILS   := $(EGCS_DIR)/as

all: $(IDO_5_3) $(IDO_7_1) $(EGCS_GCC) $(EGCS_BINUTILS)
	$(MAKE) -C fado
	$(MAKE) -C z64compress

clean:
	$(RM) -rf $(IDO_5_3_DIR) $(IDO_7_1_DIR) $(EGCS_DIR)

distclean: clean
	$(RM) -rf ido gcc_egcs

.PHONY: all clean distclean


$(IDO_5_3): | $(IDO_5_3_DIR)
	wget $(WGET_FLAGS) https://github.com/decompals/ido-static-recomp/releases/latest/download/ido-5.3-recomp-$(DOWNLOAD_OS).tar.gz
	tar xf ido-5.3-recomp-$(DOWNLOAD_OS).tar.gz -C $(IDO_5_3_DIR)
	$(RM) ido-5.3-recomp-$(DOWNLOAD_OS).tar.gz

$(IDO_7_1): | $(IDO_7_1_DIR)
	wget $(WGET_FLAGS) https://github.com/decompals/ido-static-recomp/releases/latest/download/ido-7.1-recomp-$(DOWNLOAD_OS).tar.gz
	tar xf ido-7.1-recomp-$(DOWNLOAD_OS).tar.gz -C $(IDO_7_1_DIR)
	$(RM) ido-7.1-recomp-$(DOWNLOAD_OS).tar.gz

$(EGCS_GCC): | $(EGCS_DIR)
	wget https://github.com/decompals/mips-gcc-egcs-2.91.66/releases/latest/download/mips-gcc-egcs-2.91.66-$(DETECTED_OS).tar.gz
	tar xf mips-gcc-egcs-2.91.66-$(DETECTED_OS).tar.gz -C $(EGCS_DIR)
	$(RM) mips-gcc-egcs-2.91.66-$(DETECTED_OS).tar.gz

$(EGCS_BINUTILS): | $(EGCS_DIR)
	wget https://github.com/decompals/mips-binutils-egcs-2.9.5/releases/latest/download/mips-binutils-egcs-2.9.5-$(DETECTED_OS).tar.gz
	tar xf mips-binutils-egcs-2.9.5-$(DETECTED_OS).tar.gz -C $(EGCS_DIR)
	$(RM) mips-binutils-egcs-2.9.5-$(DETECTED_OS).tar.gz

$(IDO_5_3_DIR):
	mkdir -p $@

$(IDO_7_1_DIR):
	mkdir -p $@

$(EGCS_DIR):
	mkdir -p $@

distclean: clean
