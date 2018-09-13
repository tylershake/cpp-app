# Copyright [year] [organization]
#
# Top level makefile for cpp
#

# Output config path
CONFIG_OUTPUT_PATH = ~/.config/example_cpp_app

# Local config path
LOCAL_CONFIG_PATH = ./config

# Output document path
DOC_OUTPUT_PATH = /usr/local/share/doc/example_cpp_app

# Local document path
LOCAL_DOC_PATH = ./build/docs

# Dependencies
DOXYGEN_VERSION := $(shell doxygen --version 2>/dev/null)

# Rules start here
all: dependencies cpp docs

dependencies:
ifdef DOXYGEN_VERSION
	@echo "Found Doxygen version $(DOXYGEN_VERSION)"
else
	$(error Doxygen not found)
endif

ifneq ("$(wildcard /usr/local/lib/libgtest.a)","") 
	@echo "Found GTest"
else
	$(error GTest not found)
endif

ifneq ("$(wildcard /usr/lib/x86_64-linux-gnu/libboost_filesystem.a)","")
	@echo "Found Boost"
else
	$(error Boost not found)
endif

cpp:
	$(MAKE) -C src/
	$(MAKE) -C tests/

clean:
	$(MAKE) -C src/ clean
	$(MAKE) -C tests/ clean
	$(RM) -r $(LOCAL_DOC_PATH)/*

install:
	$(MAKE) -C src/ install
	mkdir -p $(CONFIG_OUTPUT_PATH)
	cp $(LOCAL_CONFIG_PATH)/cpp_app.conf $(CONFIG_OUTPUT_PATH)
	chmod 666 $(CONFIG_OUTPUT_PATH)/cpp_app.conf
	mkdir -p $(DOC_OUTPUT_PATH)
	cp -r $(LOCAL_DOC_PATH)/* $(DOC_OUTPUT_PATH)

uninstall:
	$(MAKE) -C src/ uninstall
	$(RM) $(CONFIG_OUTPUT_PATH)/cpp_app.conf
	$(RM) -r $(DOC_OUTPUT_PATH)/*

test:
	./build/bin/test_example

docs:
	mkdir -p $(LOCAL_DOC_PATH)
	/usr/bin/doxygen Doxyfile
	$(MAKE) -C $(LOCAL_DOC_PATH)/latex/
