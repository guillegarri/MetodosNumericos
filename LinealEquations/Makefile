PYTHON = python3

.PHONEY: all
all: lineq.txt
lineq.txt: main.py gram_schmidt.py
	$(PYTHON) $< > $@

.PHONEY: clean
clean:
	$(RM) *.txt
	$(RM) *.svg
