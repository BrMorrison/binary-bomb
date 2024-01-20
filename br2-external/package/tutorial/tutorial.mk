# Buildroot makefile for the reverse engineering tutorial

TUTORIAL_VERSION = 0.1
TUTORIAL_SITE = $(TUTORIAL_PKGDIR).
TUTORIAL_SITE_METHOD = local
TUTORIAL_INSTALL_TARGET = YES
TUTORIAL_INSTALL_IMAGES = YES

# This command is just taken from the example in the buildroot docs.
define TUTORIAL_BUILD_CMDS
	$(MAKE) $(TARGET_CONFIGURE_OPTS) -C $(@D) all
endef

define TUTORIAL_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0777 $(@D)/tutorial $(TARGET_DIR)/usr/bin
endef

define TUTORIAL_INSTALL_IMAGES_CMDS
	mkdir -p $(BINARIES_DIR)/tutorial
	$(INSTALL) -D -m 0777 $(@D)/tutorial $(BINARIES_DIR)/tutorial/
	$(INSTALL) -D -m 0666 $(@D)/tutorial.html $(BINARIES_DIR)/tutorial/
	$(INSTALL) -D -m 0666 $(@D)/src/tutorial.c $(BINARIES_DIR)/tutorial/
endef

$(eval $(generic-package))
