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

# Rules start here
all: cpp docs

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
