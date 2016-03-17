TOP_DIR = .
BIN_DIR = $(TOP_DIR)/bin
SRC_DIR = $(TOP_DIR)/src
COD_DIR = $(SRC_DIR)/main/c
TEX_DIR = $(SRC_DIR)/main/tex
DOC_DIR = $(BIN_DIR)/documents
ZIP_DIR = $(BIN_DIR)/zip
SYLLABUS_DIR = $(TEX_DIR)/syllabus
ASSIGNMENTS_DIR = $(TEX_DIR)/assignments
EXAMS_DIR = $(TEX_DIR)/exams
SLIDES_DIR = $(TEX_DIR)/slides

SYLLABUS = syllabus
ASSIGNMENTS = hw01 hw01s hw02 hw02s hw03 hw03s hw04 hw04s hw05 hw05s
EXAMS = m01 m01s m02 m02s
SLIDES = ls01 ls02 ls03 ls04 ls05 ls06 ls07 ls08 ls09 ls10 ls11
ZIPS = hw01 hw02 hw03 hw04 hw05 m01 m02

ALL_DOC = $(SYLLABUS) $(ASSIGNMENTS) $(EXAMS) $(SLIDES)
ALL_PDF = $(foreach NUM, $(ALL_DOC), $(DOC_DIR)/$(NUM).pdf)

SYLLABUS_TEX = $(foreach NUM, $(SYLLABUS), $(SYLLABUS_DIR)/$(NUM).tex)
SYLLABUS_PDF = $(foreach NUM, $(SYLLABUS), $(DOC_DIR)/$(NUM).pdf)
ASSIGNMENTS_TEX = $(foreach NUM, $(ASSIGNMENTS), $(ASSIGNMENTS_DIR)/$(NUM).tex)
ASSIGNMENTS_PDF = $(foreach NUM, $(ASSIGNMENTS), $(DOC_DIR)/$(NUM).pdf)
EXAMS_TEX = $(foreach NUM, $(EXAMS), $(EXAMS_DIR)/$(NUM).tex)
EXAMS_PDF = $(foreach NUM, $(EXAMS), $(DOC_DIR)/$(NUM).pdf)
SLIDES_TEX = $(foreach NUM, $(SLIDES), $(SLIDES_DIR)/$(NUM).tex)
SLIDES_PDF = $(foreach NUM, $(SLIDES), $(DOC_DIR)/$(NUM).pdf)
ZIP_SRC = $(foreach NUM, $(ZIPS), $(COD_DIR)/$(NUM))
ZIP_DST = $(foreach NUM, $(ZIPS), $(ZIP_DIR)/$(NUM).zip)

.PHONY: clean code docs publish syllabus assignments exams slides zip bind tidy all

all: code

publish: code docs
	@echo -n "  Uploading to Remote... " && \
	./upload-files.sh
	@echo "Done."

docs: directories syllabus assignments exams slides binder tidy

directories:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(COD_DIR)
	@mkdir -p $(DOC_DIR)
	@mkdir -p $(ZIP_DIR)

syllabus: directories $(SYLLABUS_PDF)

$(SYLLABUS_PDF): $(SYLLABUS_TEX)
	@echo -n "  $(@F)... " && \
	pdflatex -halt-on-error -output-directory $(DOC_DIR) $(SYLLABUS_DIR)/$(@F:.pdf=.tex) > /dev/null && \
	pdflatex -halt-on-error -output-directory $(DOC_DIR) $(SYLLABUS_DIR)/$(@F:.pdf=.tex) > /dev/null
	@echo "Done."

assignments: directories $(ASSIGNMENTS_PDF)

$(ASSIGNMENTS_PDF): $(ASSIGNMENTS_TEX)
	@echo -n "  $(@F)... " && \
	pdflatex -halt-on-error -output-directory $(DOC_DIR) $(ASSIGNMENTS_DIR)/$(@F:.pdf=.tex) > /dev/null && \
	pdflatex -halt-on-error -output-directory $(DOC_DIR) $(ASSIGNMENTS_DIR)/$(@F:.pdf=.tex) > /dev/null
	@echo "Done."

exams: directories $(EXAMS_PDF)

$(EXAMS_PDF): $(EXAMS_TEX)
	@echo -n "  $(@F)... " && \
	pdflatex -halt-on-error -output-directory $(DOC_DIR) $(EXAMS_DIR)/$(@F:.pdf=.tex) > /dev/null && \
	pdflatex -halt-on-error -output-directory $(DOC_DIR) $(EXAMS_DIR)/$(@F:.pdf=.tex) > /dev/null
	@echo "Done."

slides: directories $(SLIDES_PDF)

$(SLIDES_PDF): $(SLIDES_TEX)
	@echo -n "  $(@F)... "
	@cd $(DOC_DIR) && \
	pdflatex -halt-on-error -shell-escape ../../$(SLIDES_DIR)/$(@F:.pdf=.tex) > /dev/null && \
	pdflatex -halt-on-error -shell-escape ../../$(SLIDES_DIR)/$(@F:.pdf=.tex) > /dev/null
	@echo "Done."

binder:
	@echo -n "  Binding documents... "
	@gs -dBATCH -dNOPAUSE -q -sDEVICE=pdfwrite -sOutputFile=$(BIN_DIR)/cs240.pdf $(ALL_PDF)
	@echo "Done."

code: directories zip

zip: directories $(ZIP_DST)

$(ZIP_DST): $(ZIP_SRC)
	@echo -n "  $(@F)... "
	@zip -rq $(ZIP_DIR)/$(@F) $(COD_DIR)/$(@F:.zip=)
	@echo "Done."

tidy:
	@find $(BIN_DIR) -name '*.log' -delete
	@find $(BIN_DIR) -name '*.aux' -delete
	@find $(BIN_DIR) -name '*.out' -delete
	@find $(BIN_DIR) -name '*.vrb' -delete
	@find $(BIN_DIR) -name '*.snm' -delete
	@find $(BIN_DIR) -name '*.toc' -delete
	@find $(BIN_DIR) -name '*.nav' -delete
	@find $(BIN_DIR) -name '*.pyg' -delete

clean:
	@echo -n "  Removing binaries... "
	@rm -rf $(BIN_DIR)
	@echo "OK"
