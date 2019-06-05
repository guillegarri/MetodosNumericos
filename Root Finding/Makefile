PYTHON = python3

.PHONEY: all
all: roots.txt
roots.txt: main_root.py functions.py Newton.py GM.py
	$(PYTHON) $< > $@

.PHONEY: clean
clean:
	$(RM) *.txt
	$(RM) *.svg
	$(RM) __pycache__
