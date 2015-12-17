TOP_DIR = .
BIN_DIR = $(TOP_DIR)/bin
SRC_DIR = $(TOP_DIR)/src
TEX_DIR = $(SRC_DIR)/main/tex
DOC_DIR = $(BIN_DIR)/documents
SYLLABUS_DIR = $(TEX_DIR)/syllabus
ASSIGNMENTS_DIR = $(TEX_DIR)/assignments
EXAMS_DIR = $(TEX_DIR)/exams
SLIDES_DIR = $(TEX_DIR)/slides

SYLLABUS = syllabus
ASSIGNMENTS = 
EXAMS = 
SLIDES = 

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

.PHONY: clean code docs syllabus assignments exams slides bind tidy all

all: code

docs: directories code build

directories:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(DOC_DIR)

build: syllabus assignments exams slides binder tidy

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
	xelatex -halt-on-error -shell-escape ../../$(SLIDES_DIR)/$(@F:.pdf=.tex) > /dev/null && \
	xelatex -halt-on-error -shell-escape ../../$(SLIDES_DIR)/$(@F:.pdf=.tex) > /dev/null
	@echo "Done."

binder:
	@echo -n "  Binding documents... "
	@gs -dBATCH -dNOPAUSE -q -sDEVICE=pdfwrite -sOutputFile=$(BIN_DIR)/course-material.pdf $(ALL_PDF)
	@echo "Done."

code:

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
	@rm -rf $(BIN_DIR)
