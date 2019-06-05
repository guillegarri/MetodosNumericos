PYTHON = python3

.PHONEY: all
all: Integration.txt

Integration.txt:	main_int.py Integration.py
	## This may take some seconds ##
	$(PYTHON) $< > $@

.PHONEY: clean
clean:
	$(RM) *.txt
	$(RM) *.svg
	$(RM) __pycache__
