DOCUMENT=sycl-1.2.1

all: git_description
	pdflatex $(DOCUMENT)
	bibtex $(DOCUMENT)
	pdflatex $(DOCUMENT)
	pdflatex $(DOCUMENT)
	pdflatex $(DOCUMENT)

publish:
	@echo " Assuming you have compiled a version that suit you"
	mkdir -p ../out/pdf
	cp -a $(DOCUMENT).pdf ../out/pdf
	@echo " If you are happy with this, commit and push ../out/pdf/$(DOCUMENT).pdf"
	@echo " for example with:"
	@echo " git commit -m 'Publish new PDF version' ../out/pdf/$(DOCUMENT).pdf"

	@echo " git push"

# Generate a file with the description of the Git repository state
git_description:
	# Use a LaTeX package such as gitinfo2 if something more complex is required,
	# but it would require using hooks (or not).
	# For now just use git describe on the worktree
	git describe --all --dirty --long > git_description.tex

clean:
	rm -f *.aux *.bbl *.blg *.lof *.log *.lot *.out *.toc
