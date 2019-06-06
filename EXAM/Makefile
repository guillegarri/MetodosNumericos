PYTHON = python3

.PHONEY: exam

exam: Exam_Solution.txt

Exam_Solution.txt: main_exam.py Krylov.py Gram_Schmidt.py
	$(PYTHON) $< > $@

.PHONEY: clean
clean:
	$(RM) *.txt
	$(RM) __pycache__
