PYTHON = python3

.PHONEY: all
all: lineq.txt lineq_C.txt

lineq_C.txt: main_C.py
	$(PYTHON) $< > $@

lineq.txt: main.py GM.py
	$(PYTHON) $< > $@

.PHONEY: clean
clean:
	$(RM) *.txt
	$(RM) *.svg
	$(RM) __pycache__
