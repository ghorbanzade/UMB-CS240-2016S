BIN_DIR = bin
SRC_DIR = src
COD_DIR = $(SRC_DIR)/c/main
TEX_DIR = $(SRC_DIR)/tex/main
DOC_DIR = $(BIN_DIR)/doc
ZIP_DIR = $(BIN_DIR)/zip
EXE_DIR = $(BIN_DIR)/exe

DOCS = \
syllabus/syllabus \
hw01/hw01 hw01/hw01s hw02/hw02 hw02/hw02s hw03/hw03 hw03/hw03s \
hw04/hw04 hw04/hw04s hw05/hw05 hw05/hw05s hw06/hw06 hw06/hw06s \
m01/m01 m01/m01s m02/m02 m02/m02s f01/f01 f01/f01s f02/f02 f02/f02s \
ls01/ls01 ls02/ls02 ls03/ls03 ls04/ls04 ls05/ls05 ls06/ls06 \
ls07/ls07 ls08/ls08 ls09/ls09 ls10/ls10 ls11/ls11 ls12/ls12 \
ls13/ls13 ls14/ls14 ls15/ls15 ls16/ls16 ls17/ls17 ls18/ls18

DOC_SRC = $(foreach NUM, $(DOCS), $(TEX_DIR)/$(NUM).tex)
DOC_DST = $(foreach NUM, $(DOC_SRC), $(DOC_DIR)/$(NUM:$(TEX_DIR)/%.tex=%.pdf))

CODE = \
hw01 hw02 hw03 hw04 hw05 hw06 \
m01 m02 f01 f02 \
ls03 ls04 ls06 \
ls07 ls08 ls09 ls10 ls11 ls12 \
ls13 ls14 ls15 ls16 ls17 ls18
COD_SRC = $(foreach NUM, $(CODE), $(COD_DIR)/$(NUM))
COD_DST = $(foreach NUM, $(COD_SRC), $(ZIP_DIR)/$(notdir $(NUM)).zip)

.PHONY: dirs code docs publish clean

all: dirs code docs

dirs:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(DOC_DIR)
	@mkdir -p $(ZIP_DIR)
	@mkdir -p $(EXE_DIR)

code: dirs compile

compile: dirs $(COD_DST)

$(COD_DST): $(COD_SRC)
	@echo -n "  Compiling $(@F:.zip=)... "
	@mkdir -p $(EXE_DIR)/$(@F:.zip=)
	@$(MAKE) --no-print-directory -C $(<D)/$(@F:.zip=) > /dev/null
	@zip -rjq $(ZIP_DIR)/$(@F) $(<D)/$(@F:.zip=)
	@echo "OK"

docs: dirs $(DOC_DST)
	@echo -n "  Binding documents... "
	@gs -dBATCH -dNOPAUSE -q -sDEVICE=pdfwrite \
		-sOutputFile=$(BIN_DIR)/cs240.pdf \
		$(foreach NUM, $(DOC_DST), $(DOC_DIR)/$(notdir $(NUM)))
	@echo "OK"

$(DOC_DST): $(DOC_SRC)
	@echo -n "  Building $(@F)... "
	@pdflatex -halt-on-error -output-directory $(DOC_DIR) \
		-shell-escape $(@:$(DOC_DIR)/%.pdf=$(TEX_DIR)/%.tex)
	@pdflatex -halt-on-error -output-directory $(DOC_DIR) \
		-shell-escape $(@:$(DOC_DIR)/%.pdf=$(TEX_DIR)/%.tex) > /dev/null
	@rm -rf $(DOC_DIR)/$(@F:.pdf=).aux
	@rm -rf $(DOC_DIR)/$(@F:.pdf=).log
	@rm -rf $(DOC_DIR)/$(@F:.pdf=).nav
	@rm -rf $(DOC_DIR)/$(@F:.pdf=).out
	@rm -rf $(DOC_DIR)/$(@F:.pdf=).snm
	@rm -rf $(DOC_DIR)/$(@F:.pdf=).toc
	@rm -rf $(DOC_DIR)/$(@F:.pdf=).vrb
	@echo "OK"

publish: all
	@echo -n "  Uploading to Remote... " && \
	./upload-files.sh
	@echo "OK"

clean:
	@echo -n "  Removing binaries... "
	@rm -rf $(BIN_DIR)
	@echo "OK"
