# Buildroot makefile for the binary bomb

BOMB_VERSION = 0.1
BOMB_SITE = $(BOMB_PKGDIR).
BOMB_SITE_METHOD = local
BOMB_INSTALL_TARGET = YES
BOMB_INSTALL_IMAGES = YES

# This command is just taken from the example in the buildroot docs.
define BOMB_BUILD_CMDS
	$(MAKE) $(TARGET_CONFIGURE_OPTS) -C $(@D) all
endef

define BOMB_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0777 $(@D)/bomb $(TARGET_DIR)/usr/bin
endef

define BOMB_INSTALL_IMAGES_CMDS
	$(INSTALL) -D -m 0777 $(@D)/bomb $(BINARIES_DIR)/
	$(INSTALL) -D -m 0666 $(@D)/guide.txt $(BINARIES_DIR)/
	$(INSTALL) -D -m 0666 $(@D)/src/bomb.c $(BINARIES_DIR)/
endef

$(eval $(generic-package))
