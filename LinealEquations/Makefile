PYTHON = python3

.PHONEY: all
all: lineq.txt
lineq.txt: main.py GM.py
	$(PYTHON) $< > $@

.PHONEY: clean
clean:
	$(RM) *.txt
	$(RM) *.svg
