# Copyright (c) 2012-2019 The Khronos Group, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

include ../sycl_version.txt

DOCUMENT=sycl-$(SYCLVERSION)


all: git_description version_config
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

	# Use printf for more consistent escaping behavior across different shells
	printf "\\\newcommand{\\\GitDescribe}{%s}\n" `git describe --all --dirty --long` > git_description.tex

version_config:
	printf \
	"\\\def\\\SYCLVERSION{$(SYCLVERSION)} \n\
	\\\def\\\SYCLLANGVERSION{$(SYCLLANGVERSION)} \n\
	\\\def\\\DOCUMENTVERSION{$(SYCLREVISION)} \n\
	\\\def\\\SYCLNAME{$(SYCLNAME)} \n\
	\\\def\\\OPENCLVERSION{$(OPENCLVERSION)}" > version_config.tex


clean:
	rm -f sycl-1.2.1.pdf *.aux *.bbl *.blg *.lof *.log *.lot *.out *.toc git_description.tex version_config.tex
